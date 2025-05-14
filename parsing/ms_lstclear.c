/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:35:34 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/14 13:53:51 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ms_lstclear(t_token **lst, void (*del)(void *))
{
	t_token	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ms_lstdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}
