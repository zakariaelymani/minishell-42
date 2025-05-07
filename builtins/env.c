/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:38:16 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/07 10:58:21 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"


void print_strcut(t_env *env)
{
	t_env *tmp;

	tmp = env;
	while (tmp)
	{
		printf("%s%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

int env_cmd(t_env *env)
{
	t_env *tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->status != -1)
		{
			if (tmp->value && *tmp->value)
				printf("%s%s\n",tmp->key, tmp->value);
			else 
				printf ("%s\n", tmp->key);
		}
		tmp = tmp->next;
	}
	return (0);
}