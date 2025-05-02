/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:51:07 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/01 18:13:31 by zel-yama         ###   ########.fr       */
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

	// int fd = open (cmd[0], O_DIRECTORY)   ./
	// fd != -1 
	// is not a O_DIRECTORY
	// else
	// is a diretory return 126 exit code
char *check_is_exsist_or_excuteble(char *cmd, t_env **env)
{
	if (access(cmd, F_OK) != 0)
	{
		(*env)->exit_sta = 127;
		return (free(cmd), cmd = NULL, NULL);
	}
	else if (access(cmd, X_OK) != 0)
	{
		perror("minishell");
		(*env)->exit_sta = 126;
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
	
	if (!cmd || !*cmd)
		return (NULL);
	path = while_find_path(env);
	if (!path || !*path)
		return (check_is_exsist_or_excuteble(cmd, env));
	splited = ft_split(path, ':');
	(1) && (free(path), path = NULL);
	i = 0;
	joined = ft_strjoin("/", cmd);
	(1) && (free(cmd), cmd = NULL);
	while (splited[i])
	{
		cmd = ft_strjoin(splited[i], joined);
		if (access(cmd, F_OK) == 0)
			return (free_while(splited), free(joined), joined = NULL, check_is_exsist_or_excuteble(cmd, env));
		free(cmd);
		cmd = NULL;
		i++;
	}
	return (free_while(splited), check_is_exsist_or_excuteble(joined, env));
}
