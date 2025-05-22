/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ifnot_exists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:49:21 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/17 15:42:56 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	add_var_just_not_exists(t_env **env, char *var_name, char *value)
{
	t_env	*tmp;

	if (!env | !*env)
		return ;
	tmp = (*env);
	while (tmp)
	{
		if (compare(var_name, tmp->key) == 0)
			return ;
		tmp = tmp->next;
	}
	ft_lstadd_back(env, node(ft_strjoin(var_name, value), 1));
}
