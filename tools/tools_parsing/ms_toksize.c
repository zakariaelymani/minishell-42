/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_toksize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:22:21 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/10 16:31:32 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ms_toksize(t_token *lst)
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
