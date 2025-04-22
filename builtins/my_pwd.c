/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:30:24 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/21 12:20:15 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void my_pwd(t_env **env)
{
    char	*pwd;

    pwd = getcwd(NULL, 0);
    if (!pwd || !*pwd)
        perror ("pwd");
    printf("%s\n", pwd);
    change_value_var(env, "_", "=pwd");
}