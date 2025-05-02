/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:53:32 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/29 12:38:47 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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

int change_dir(char **new_path, t_env **env)
{
	t_env   *tmp;
	char    *tmp_path;
	char    *path;

	tmp = (*env);
	if (chdir(new_path[1]) != 0)
	{
		perror("cd");
		return (1);
	}
	while (tmp)
	{
		if (ft_strncmp(tmp->key, "PWD", 3) == 0 && ft_strlen(tmp->key) == 3)
		{
			tmp_path = getcwd(NULL, 0);
			free(tmp->value);
			tmp->value = NULL;
			path = ft_strjoin("=", tmp_path);
			tmp->value = ft_strdup(path);
			(1) && (free(path), change_old(env, tmp_path), path = NULL);
			return (0);
		}
		tmp = tmp->next;
	}
	return (0)
}
