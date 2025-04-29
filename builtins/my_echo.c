/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:37:25 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/26 19:36:01 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void    my_echo(char *op, char *string, t_env **env)
{
    printf("%s" ,string);
    if (op && *op)
        printf("\n");
    change_value_var(env, "_", "=echo");    
}