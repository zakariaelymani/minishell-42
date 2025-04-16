/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:53:32 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/15 16:55:31 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//change oldpwd var in evn var  
void change_old(t_env **env, char *tmp_path)
{
    t_env *tmp;

    tmp = (*env);
    while (tmp)
    {
        if (ft_strncmp(tmp->key, "OLDPWD", 6) == 0 && ft_strlen(tmp->key) == 6)
        {
            free(tmp->value);
            tmp->value = NULL;
            tmp->value = ft_strdup(tmp_path);
            free(tmp_path);
        }
        tmp = tmp->next;
    }  
}

void change_dir(char *new_path, t_env **env)
{
    t_env   *tmp;
    char    *tmp_path;
    char    *path;

    tmp = (*env);
    if (!new_path || !*new_path || chdir(new_path) != 0)
    {
        perror("cd");
       // exit(1);
       return ;
    }
    while (tmp)
    {
        if (ft_strncmp(tmp->key, "PWD", 3) == 0 && ft_strlen(tmp->key) == 3)
        {
            tmp_path = ft_strdup(tmp->value);
            free(tmp->value);
            path = ft_strjoin("=", new_path);//THIS WELL ROMAVE IF FOUND TI USE LESS 
            tmp->value = ft_strdup(path);
            (free(path), change_old(env, tmp_path));
            break;
        }
        tmp = tmp->next;
    }
    //exit(0);
}
