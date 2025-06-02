/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:38:16 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/22 13:24:55 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"


char *join_env(t_env *env)
{
	t_env *tmp;
	char *line;
	char *prev;

	prev = NULL;
	tmp = env->next;
	while (tmp)
	{
		if (tmp->status != -1)
		{
			line = free_and_join(tmp->key, tmp->value, 0);
			line = free_and_join(line, "\n", 1);
			prev = free_and_join(prev, line, 3);
		}
		tmp = tmp->next;
	}
	return (prev);
}

int env_cmd(t_env *env)
{
	char	*line;
	
	if (!env)
		return (1);
	line = join_env(env);
	if (write(1, line, ft_strlen(line)) == -1)
		return (free(line), 1);
	free(line);
	return (0);
}