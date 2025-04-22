/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_value_struct_env.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:18:58 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/17 13:27:30 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void change_value_var(t_env **env, char *var_name, char *new_val)
{
    t_env *tmp_env;
    
    tmp_env = (*env);
    while (tmp_env)
    {
        if (compare_key(var_name, tmp_env) == -1)
        {
            free(tmp_env->value);
            tmp_env->value = NULL;
            tmp_env->value = ft_strdup(new_val);
            free(new_val);
            return ;
        }
        tmp_env = tmp_env->next;
    }
}