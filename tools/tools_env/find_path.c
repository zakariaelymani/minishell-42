/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:51:07 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/09 12:37:32 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

char	*check_is_exsist_or_excuteble(char *cmd, t_env **env)
{
	int	fd;

	fd = open(cmd, __O_DIRECTORY);
	if (fd > -1)
		close(fd);
	if (access(cmd, F_OK) != 0)
	{
		(*env)->exit_sta = 127;
		my_perror("minishell: ", cmd, ": No such file or directory\n");
		return (NULL);
	}
	else if (access(cmd, X_OK) != 0)
	{
		my_perror("minishell: ", cmd, ": Permission denied \n");
		(*env)->exit_sta = 126;
		return (NULL);
	}
	else if (fd != -1)
	{
		(*env)->exit_sta = 126;
		my_perror("minishell: ", cmd, ": input is directory\n");
		return (NULL);
	}
	return (cmd);
}

char	*find_path_to_cmd(t_env **env, char *cmd, int i)
{
	char	*path;
	char	**splited;
	char	*joined;

	if (!cmd)
		return ((*env)->exit_sta = 0, NULL);
	if (ft_strchr(cmd, '/'))
		return (check_is_exsist_or_excuteble(cmd, env));
	path = return_value(*env, "PATH", 1);
	if (!path || !*path)
		return (check_is_exsist_or_excuteble(cmd, env));
	splited = ft_split(path, ':');
	path = cmd;
	joined = ft_strjoin("/", cmd);
	while (*path && splited[i])
	{
		cmd = ft_strjoin(splited[i], joined);
		if (access(cmd, F_OK | X_OK) == 0)
			return (free_while(splited), free(joined), joined = NULL, cmd);
		free_vars(cmd, NULL, NULL, NULL);
		i++;
	}
	my_perror("minishell: ", path, ": command not found\n");
	(*env)->exit_sta = 127;
	return (free_while(splited), free(joined), NULL);
}
