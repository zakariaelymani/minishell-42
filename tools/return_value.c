/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:38:48 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/20 11:41:40 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char *return_value(t_env *env, char *var_name)
{
    t_env *tmp;
    
    tmp = env;
    while (tmp)
    {
        if (compare(var_name, tmp->key) == 0)
            return (tmp->value+1);
        tmp = tmp->next;
    }
    return (NULL);
}