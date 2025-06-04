/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:53:32 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/04 20:05:18 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_ishe_return(char *path, int *s)
{
	int i;
	int how;
	
	i = 0;
	how = 0;
	if (!path)
		return (how);
	while (path[i])
	{
		if (path[i] == '.' && path[i + 1] == '.' && (path[i + 2] == '/' || path[i + 2] == '\0'))
		{
			if (path[i + 2] == '\0')
					return (*s += 3, how++, how);
			i += 3;
			*s += 3;
			how++;
		}
		else
			return (how);
			
	}
	return (how);
}

void change_pwd(t_env **env, char *input)
{	
	char *tmp_path;
	char *path;


	tmp_path = getcwd(NULL, 0);
	if (!tmp_path || !*tmp_path)
		perror("cd: error retrieving current directory: getcwd: cannot access parent directories:");
	change_value_var(env, "OLDPWD", return_value(*env, "PWD", 0));
	if (tmp_path)
		path = free_and_join("=", tmp_path, 2);//leaks 
	else
	{
		path = free_and_join("/", input, 0);
		path = free_and_join(return_value(*env, "PWD", 0), path, 0);
	}
	free_vars((*env)->value, NULL, NULL, NULL);	
	(*env)->value = ft_strdup(path);
	change_value_var(env, "PWD", path);
	free_vars(path ,NULL, NULL, NULL);
}


char *change_path(char *new_path, char *pwd, char *path, char *line)
{
	int how;
	int	i;
	int s;
	
	s = 0;
	how = check_ishe_return(new_path, &s);
	if (how == 0 || !pwd || !path)
		return (free_vars(path, NULL, NULL, NULL), new_path);
	i = ft_strlen(pwd);
	if (pwd[i - 1] == '/')
		i--;
	while (how > 0)
	{
		if (pwd[i - 1] == '/')
				how--;
		i--;
	}
	if (new_path[s])
	{
		path = ft_substr(new_path, s, ft_strlen(new_path));
		path = free_and_join("/", path, 2);
		write(2, "here\n", 5);
	}
	line = ft_substr(pwd , 0, i);
	line = free_and_join(line, path, 1);
	printf("%s\n", line);
	return (line);
}

int	change_dir(char **new_path, t_env **env)
{
	char    *path;
	char	*line;
	
	line = NULL;
	(void)line;
	(void)path;
	if (find_env(new_path) > 2)
		return (safe_write(2, "minishell: cd:  too many arguments\n", 36) , 1);
	//path = change_path(new_path[1], return_value(*env, "PWD", 1), getcwd(NULL, 0), line);
	if (chdir(new_path[1]) != 0)
		return(perror("minishell: cd"), 1);//duble free here if you free path leaks
	change_pwd(env, new_path[1]);
	return (0);
}
