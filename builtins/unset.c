/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:27:03 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/09 09:59:34 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	removenode(t_env **env, char *var)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = (*env)->next;
	prev = NULL;
	while (tmp)
	{
		if (compare(var, tmp->key) == 0)
		{
			if (prev == NULL)
				*env = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp->key);
			(free(tmp->value), free(tmp));
			tmp = NULL;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

int	unset(t_env **env, char **splited)
{
	int	i;

	if (!splited[1])
		return (0);
	i = 1;
	while (splited[i])
	{
		removenode(env, splited[i]);
		i++;
	}
	change_value_var(env, "_", "=unset");
	return (0);
}
