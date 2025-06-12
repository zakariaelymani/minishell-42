/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:44:46 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/08 09:57:24 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

char	*extract_key(char *value)
{
	int		i;
	char	*new_key;
	int		x;

	i = 0;
	x = 0;
	if (!value)
		return (NULL);
	while (value[i] && value[i] != '=' && value[i] != '+')
		i++;
	new_key = ft_malloc(sizeof(char) * (i + 1));
	while (x < i)
	{
		new_key[x] = value[x];
		x++;
	}
	new_key[x] = '\0';
	return (new_key);
}

t_env	*node(char *value, int flag)
{
	t_env	*node;
	char	*val;

	node = NULL;
	if (!value)
		return (NULL);
	val = ft_strchr(value, '=');
	node = (t_env *)ft_malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	ft_memset(node, 0, sizeof(node));
	node->status = 1;
	node->exit_sta = 0;
	if (!val)
	{
		node->status = -1;
		node->value = ft_strdup("");
	}
	else
		node->value = ft_strdup(val);
	node->key = extract_key(value);
	if (flag == 1)
		free(value);
	node->next = NULL;
	return (node);
}
