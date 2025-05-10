/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:30:24 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/10 16:51:59 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int my_pwd(t_env **env)
{
    char	*pwd;

    (void)*env;
    pwd = getcwd(NULL, 0);
    if (!pwd || !*pwd)
    {
        perror ("pwd");
        return (1);
    } 
    printf("%s\n", pwd);
    free(pwd);
    pwd = NULL;
    return (0);
}