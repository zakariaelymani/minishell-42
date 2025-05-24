/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:40:37 by abenkaro          #+#    #+#             */
/*   Updated: 2024/11/02 11:49:25 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	*abort_map(t_token *new_list, void (*del)(void *))
{
	ft_tokclear(&new_list, del);
	return (NULL);
}

t_token	*ms_tokmap(t_token *lst, void *(*f)(void *), void (*del)(void *))
{
	t_token	*new_list;
	t_token	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			return (abort_map(new_list, del));
		new_node =ms_toknew(content);
		if (!new_node)
		{
			del(content);
			return (abort_map(new_list, del));
		}
		ms_tokappend(&new_list, new_node);
		lst = lst->next;
	}
	ft_tokclear(&lst, del);
	return (new_list);
}
