/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:27:03 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/29 12:33:41 by zel-yama         ###   ########.fr       */
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
			free(tmp);
			tmp = NULL;
			return ;
		}
		prev = tmp;
		tmp	= tmp->next;
	}
}

int	unset(t_env **env, char **splited)
{
	int     i;

	if (!splited[1])
		return (0);
	i = 1;
	while (splited[i])
	{
		if (check_name(splited[i])  == 1)
			return (1);
		else		
			removenode(env, splited[i]);
	   i++;
	}
	free_while(splited);
	return (0);
}