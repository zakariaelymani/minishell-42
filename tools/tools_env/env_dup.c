/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:42:20 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/29 12:33:16 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

t_env	*dup_list(t_env *env)///new
{
	t_env	*tmp_head;
	t_env	*tmp;
	t_env	*hold_env;	

	hold_env = env->next;
	tmp = NULL;
	tmp = node(ft_strjoin(hold_env->key, hold_env->value), 1); //new add 1 to remove leaks
	tmp_head = tmp;
	hold_env = hold_env->next;
	while (hold_env)
	{
		tmp->next = node(ft_strjoin(hold_env->key, hold_env->value), 1);//new add 1 leaks
		tmp = tmp->next;
		hold_env = hold_env->next;
	}
	return (tmp_head);
}
