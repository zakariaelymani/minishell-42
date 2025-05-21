/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:53:32 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/21 11:57:09 by zel-yama         ###   ########.fr       */
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


char *change_path(char *new_path, char *pwd, char *path, char *line)
{
	int how;
	int	i;
	int s;
	
	(1) && (s = 0 , path = NULL);
	how = check_ishe_return(new_path, &s);
	if (how == 0 || !pwd)
		return (new_path);
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
	}
	line = ft_substr(pwd , 0, i);
	line = free_and_join(line, path, 3);
	return (line);
}

int	change_dir(char **new_path, t_env **env)
{
	char    *tmp_path;
	char    *path;
	char	*path_to_change;
	char	*line;
	
	line = NULL;
	path_to_change = NULL;
	path = change_path(new_path[1], return_value(*env, "PWD"), path_to_change, line);
	if (chdir(path) != 0)
			return(perror("minishell: cd"),  1);//duble free here if you free path leaks
	tmp_path = getcwd(NULL, 0);
	if (!tmp_path)
		perror("d: error retrieving current directory: getcwd: cannot access parent directories:");
	change_value_var(env, "OLDPWD", return_value(*env, "PWD"));
	free(path);
	path = ft_strjoin("=", tmp_path);//leaks 
	change_value_var(env, "PWD", path);
	(free(path), free(tmp_path));
	return (0);
}
