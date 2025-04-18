/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:42:08 by zel-yama          #+#    #+#             */
/*   Updated: 2025/01/27 14:56:11 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_and_exit(char d)
{
	if (d == 'f')
		ft_putstr_fd("--ERORR NO FILE-- ", 2);
	if (d == 'e')
		ft_putstr_fd("--ERROR NO ENVIRMENET-- ", 2);
	if (d == 'd')
		ft_putstr_fd("--ERROR IN FORK-- ", 2);
	if (d == 'r')
		ft_putstr_fd("--ERROR THERE ON ENOUTHG ARGUMENTS-- ", 2);
	if (d == 'c')
		ft_putstr_fd("--ERROR COMMAND NOT FOUNDE-- ", 2);
	if (d == 'p')
		ft_putstr_fd("--ERROR IN PIPE FUNCTOIN-- ", 2);
	if (d == 'x')
		ft_putstr_fd("--ERROR EXCEVE FAILED--", 2);
	if (d == 'w')
		ft_putstr_fd("--ERROR IN WATING--", 2);
	exit(1);
}

char	*findpath(char **env)
{
	char	*path;
	int		i;
	int		y;

	i = 0;
	path = "PATH=/";
	y = 0;
	while (env[i] && path[y])
	{
		y = 0;
		while (path[y])
		{
			if (path[y] == env[i][y])
			{
				y++;
			}
			else
				break ;
		}
		i++;
	}
	return (env[i - 1]);
}

int	check_spialcharac(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**find_path_andfree(char **env)
{
	char	*path;
	char	*removeslash;
	char	**splited;

	path = findpath(env);
	removeslash = ft_strchr(path, '/');
	splited = ft_split(removeslash, ':');
	return (splited);
}

char	*find_cmdpath(char **env, char *cmd)
{
	char	*path;
	char	**splited;
	char	**cmds;
	int		i;
	int		check;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	cmds = ft_split(cmd, ' ');
	cmd = cmds[0];
	if (check_spialcharac(cmds[0]) == 0)
		return (NULL);
	splited = find_path_andfree(env);
	cmd = ft_strjoin("/", cmd);
	while (splited[i])
	{
		path = ft_strjoin(splited[i], cmd);
		check = access(path, F_OK | X_OK);
		if (check == 0)
			return (free_while(cmds), free(cmd), free_while(splited), path);
		free(path);
		i++;
	}
	return (free(cmd), free_while(cmds), free_while(splited), NULL);
}
