/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:42:20 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/15 16:42:36 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

//dup linked list of env 
t_env *dup_list(t_env *env)
{
    int		i;
    int		len;
    t_env	*dub_env;
	t_env	*tmp;
	t_env	*tmp_env;
    
    len = ft_lstsize(env);
    i = 1;
	dub_env = node(ft_strjoin(env->key, env->value));
	tmp = dub_env;
	tmp_env = env;
	while (i < len && tmp_env)
	{
		tmp_env = tmp_env->next;
		dub_env->next = node(ft_strjoin(tmp_env->key, tmp_env->value));
		dub_env = dub_env->next;
		i++;
	}
	return (tmp);
	
}