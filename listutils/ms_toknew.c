/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_toknew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:22:11 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/16 17:40:05 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_local.h"

t_token	*ms_toknew(char *name, t_type type)
{
	t_token	*result;

	result = (t_token *)malloc(sizeof(t_token));
	if (!result)
		return (NULL);
	result->type = type;
	result->content = name;
	result->next = NULL;
	return (result);
}
