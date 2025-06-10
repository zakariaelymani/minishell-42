/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:06:25 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/10 16:31:23 by abenkaro         ###   ########.fr       */
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
