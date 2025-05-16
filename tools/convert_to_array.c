/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:09:02 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/15 15:42:13 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	**convert_strcut_array(t_env *env)
{
    char	**env_map;
    int		len;
	int		i;

	len = ft_lstsize(env);
	env_map = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (env)
	{
		if (env ->status != -1)
		{
			env_map[i] = ft_strjoin(env->key, env->value);
			i++;
		}
		env = env->next;
	}
	env_map[i] = NULL;
	return (env_map);
}