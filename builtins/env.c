/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:38:16 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/08 09:06:24 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*join_env(t_env *env)
{
	t_env	*tmp;
	char	*line;
	char	*env_line;

	tmp = env->next;
	env_line = NULL;
	while (tmp)
	{
		if (tmp->status != -1)
		{
			line = free_and_join(tmp->key, tmp->value, 0);
			line = free_and_join(line, "\n", 1);
			env_line = free_and_join(env_line, line, 3);
		}
		tmp = tmp->next;
	}
	return (env_line);
}

int	env_cmd(t_env *env)
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
