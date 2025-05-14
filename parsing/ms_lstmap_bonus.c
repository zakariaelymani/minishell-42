/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:40:37 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/14 13:55:33 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*abort_map(t_token *new_list, void (*del)(void *))
{
	ms_lstclear(&new_list, del);
	return (NULL);
}

t_token	*ms_lstmap(t_token *lst, void *(*f)(void *), void (*del)(void *))
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
		new_node = ms_newtoken(content);
		if (!new_node)
		{
			del(content);
			return (abort_map(new_list, del));
		}
		ms_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
