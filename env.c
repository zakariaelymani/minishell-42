/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:38:16 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/16 12:41:50 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"




void env_cmd(t_env *env)
{
    t_env *tmp;

    tmp = env;
    while (tmp)
    {
        if (tmp->status != -15)
            printf("%s%s\n",tmp->key, tmp->value);
        tmp = tmp->next;
    }
}