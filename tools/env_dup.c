/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:42:20 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/17 16:22:05 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_env *dup_list(t_env *env)
{
	t_env *dup_head;
	t_env *dup_tail;
	t_env *tmp_env;
	t_env *new_node;

	tmp_env = env;
	while (tmp_env)
	{
		new_node = node(ft_strjoin(tmp_env->key, tmp_env->value, 1))
		if (!dup_head)
		{
			dup_head = new_node;
			dup_tail = new_node;
		}
		else
		{
			dup_tail->next = new_node;
			dup_tail = new_node;
		}
		tmp_env = tmp_env->next;
	}
	return (dup_head);
}
