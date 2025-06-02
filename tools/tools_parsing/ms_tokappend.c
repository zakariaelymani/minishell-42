/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:06:25 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/20 13:37:31 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ms_tokappend(t_token **lst, t_token *new)
{
	t_token	*last;

	if (!lst || !new)
		return (0);
	if (!*lst)
		*lst = new;
	else
	{
		last = ms_toklast(*lst);
		last->next = new;
		new->prev = last;
	}
	return (1);
}
