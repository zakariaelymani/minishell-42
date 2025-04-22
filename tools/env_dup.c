/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:42:20 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/19 13:10:08 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

//dup linked list of env 
t_env *dup_list(t_env *env)
{
    t_env *dup_head = NULL;
    t_env *dup_tail = NULL;
    t_env *tmp_env = env;

    while (tmp_env)
    {
        t_env *new_node = malloc(sizeof(t_env));
        if (!new_node) // always check malloc
            return NULL;
        new_node->key = ft_strdup(tmp_env->key);
        new_node->value = tmp_env->value ? ft_strdup(tmp_env->value) : NULL;
        new_node->next = NULL;
        if (!dup_head)  // first node
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
    return dup_head;
}
