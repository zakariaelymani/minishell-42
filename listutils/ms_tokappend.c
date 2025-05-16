/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:06:25 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/16 17:39:10 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_local.h"

void	ms_tokappend(t_token **lst, t_token *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ms_toklast(*lst)->next = new;
}
