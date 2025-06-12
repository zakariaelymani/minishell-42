/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:38:48 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/24 16:03:44 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

char	*return_value(t_env *env, char *var_name, int flag)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (compare(var_name, tmp->key) == 0 && tmp->status != -1)
		{
			if (flag == 1)
				return (tmp->value + 1);
			else
				return (tmp->value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
