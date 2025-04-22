/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:27:03 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/21 12:20:18 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"



void removenode(t_env **env, char *var)
{
    t_env   *tmp;
    t_env   *prev;
    size_t	lenvar;

    tmp = (*env);
	lenvar = ft_strlen(var);
    prev = NULL;
    while (tmp)
    {
        if (ft_strncmp(var, tmp->key, lenvar) == 0  && lenvar == ft_strlen(tmp->key))
		{
			if (prev == NULL)
				*env = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp	= tmp->next;
    }
    
}

void unset(t_env **env, char *vars)
{
    char    **splited;
    int     i;

    if (!vars || !*vars)
        return;
    i = 0;
    splited = ft_split(vars, ' ');
    while (splited[i])
    {
       removenode(env, splited[i]);
	   i++;
    }
	free_while(splited);
    change_value_var(env, "_", "=unset");
   // ft_exit(0);
}