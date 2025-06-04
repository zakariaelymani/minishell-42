/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:51:07 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/29 10:39:48 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

int	check_char_is_there(char *cmd, char c)
{
	int	i;

	if (!cmd || !*cmd)
		return (0);
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*check_is_exsist_or_excuteble(char *cmd, t_env **env)
{
	if (access(cmd, F_OK) != 0)
	{
		(*env)->exit_sta = 127;
		write(2, "No such file or directory\n", 27);
		return (free(cmd), cmd = NULL, NULL);
	}
	else if (access(cmd, X_OK) != 0)
	{
		write(2, "command is not excutble;\n", 26);
		(*env)->exit_sta = 126;
		return (free(cmd), cmd = NULL, NULL);
	}
	else if (open(cmd, O_DIRECTORY) != -1)
	{
		(*env)->exit_sta = 126;
		write(2, "input is directory\n", 20);
		return (free(cmd), cmd = NULL, NULL);
	}
	return (cmd);
}

char	*find_path_to_cmd(t_env **env, char *cmd, int i)
{
	char	*path;
	char	**splited;
	char	*joined;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (check_is_exsist_or_excuteble(cmd, env));
	path = return_value(*env, "PATH", 1);
	if (!path || !*path)
		return (check_is_exsist_or_excuteble(cmd, env));
	splited = ft_split(path, ':');
	joined = ft_strjoin("/", cmd);///leaks
	while (splited[i])
	{
		cmd = ft_strjoin(splited[i], joined);
		if (access(cmd, F_OK | X_OK) == 0)
			return (free_while(splited), free(joined), joined = NULL, cmd);
		(1) && (free(cmd), i++);
	}
	write(2, "command not found\n", 19);
	(*env)->exit_sta = 127;
	return (free_while(splited), free(joined), NULL);// new free leaks 
}
