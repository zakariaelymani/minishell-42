/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:53:32 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/09 11:57:46 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	change_pwd(t_env **env, char *input)
{
	char	*tmp_path;
	char	*path;

	tmp_path = getcwd(NULL, 0);
	if (!tmp_path || !*tmp_path)
		perror("cd: error retrieving current \
			directory: getcwd: cannot access parent directories:");
	change_value_var(env, "OLDPWD", return_value(*env, "PWD", 0));
	if (tmp_path)
		path = free_and_join("=", tmp_path, 2);
	else
	{
		path = free_and_join("/", input, 0);
		path = free_and_join(return_value(*env, "PWD", 0), path, 2);
	}
	free_vars((*env)->value, NULL, NULL, NULL);
	(*env)->value = ft_strdup(path);
	change_value_var(env, "PWD", path);
	free_vars(path, NULL, NULL, NULL);
}

int	change_dir_to_home(t_env *env, int fd)
{
	char	*value;

	if (fd == -1)
		perror("you don't have Permission cwd ");
	value = return_value(env, "HOME", 1);
	if (!value)
		return (perror("minishell cd don't unset HOME"), 1);
	if (chdir(value) != 0)
		return (perror("minishell cd"), 1);
	return (0);
}

int	change_dir(char **new_path, t_env **env)
{
	int fd;

	if (!*((*env)->value + 1))
		return (perror("minishell you run minishell in unexsited dir"), 1);
	fd = open(".", __O_DIRECTORY);
	if (fd != -1)
		close(fd);
	if (find_env(new_path) > 2)
		return (safe_write(2, "minishell: cd:  too many arguments\n", 36), 1);
	if (!new_path[1] || fd == -1)
	{
		if (change_dir_to_home(*env, fd) == 1)
			return (change_pwd(env, new_path[1]), 1);
	}
	else if (chdir(new_path[1]) != 0)
		return (my_perror("minishell: ", new_path[1], NULL), perror(" "), 1);
	change_pwd(env, new_path[1]);
	return (0);
}
