/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:32:55 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/10 16:31:04 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	special_delim(int c)
{
	if (ft_strchr("'\"_?$", c))
		return (1);
	return (0);
}

void	varlen(size_t *len, char *str)
{
	*len = 0;
	while (str[*len] && (ft_isalnum(str[*len]) || str[*len] == '_'))
		*len += 1;
}
