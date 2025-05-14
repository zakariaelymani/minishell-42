/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:22:21 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/14 13:55:41 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ms_lstsize(t_token *lst)
{
	int	result;

	if (!lst)
		return (0);
	result = 1;
	while (lst->next != NULL)
	{
		result++;
		lst = lst->next;
	}
	return (result);
}
