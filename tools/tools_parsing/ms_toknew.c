/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_toknew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:22:11 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/10 16:31:31 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_token	*ms_toknew(char *name, t_type type)
{
	t_token	*result;

	result = (t_token *)ft_malloc(sizeof(t_token));
	if (!result)
		return (NULL);
	result->type = type;
	result->content = name;
	result->next = NULL;
	result->prev = NULL;
	return (result);
}
