/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:35:34 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/16 17:36:16 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_local.h"

void	ms_tokclear(t_token **lst, void (*del)(void *))
{
	t_token	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ms_tokdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}
