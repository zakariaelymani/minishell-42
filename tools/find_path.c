/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:51:07 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/20 15:15:42 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tools.h"

char *while_find_path(t_env **env)
{
	t_env *tmp;

	tmp = (*env);

	while (tmp)
	{
		if (compare(tmp->key, "PATH") == 0)
			return (ft_strdup(tmp->value + 1));
		tmp = tmp->next;	
	}
	return (NULL);
}
int check_char_is_there(char *cmd, char c)
{
	int i;
	
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


char *check_is_exsist_or_excuteble(char *cmd, t_env **env)
{
	
	if (access(cmd, F_OK ) != 0)
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
		(*env)->exit_sta =126;
		write(2, "input is directory\n", 20);
		return (free(cmd), cmd = NULL, NULL);
	}
	return (cmd);
}

char	*find_path_to_cmd(t_env **env, char *cmd)
{
	char	*path;
	char	**splited;
	int		i;
	char 	*joined;
	char 	*cmd2;
	
	cmd2 = cmd;
	if (!cmd || !*cmd)
		return (NULL);
	if (check_char_is_there(cmd, '/') == 1)
		 return (check_is_exsist_or_excuteble(cmd, env));	
	path = while_find_path(env);
	if (!path || !*path)
		return (check_is_exsist_or_excuteble(cmd, env));
	splited = ft_split(path, ':');
	(1) && (free(path), path = NULL);
	i = 0;
	joined = ft_strjoin("/", cmd);///leaks
	while (splited[i])
	{
		cmd = ft_strjoin(splited[i], joined);
		if (access(cmd, F_OK | X_OK) == 0)
			return (free_while(splited), free(joined), joined = NULL, cmd);
		free(cmd);
		i++;
	}
	write(2, "command not found\n",19);
	(*env)->exit_sta = 127;
	return (free(cmd2), cmd2 = NULL, NULL);
}
