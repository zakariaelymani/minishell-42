/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:34:35 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/14 18:34:37 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	exit_status(char **str, int code)
{
	char	tmp[12];

	*str += 1;
	ft_cpynbr(tmp, code);
	return (ft_strlen(tmp));
}

static size_t	expand_pid(char **str)
{
	char	tmp[12];

	*str += 1;
	ft_cpynbr(tmp, 134237);
	return (ft_strlen(tmp));
}

size_t	symbol_size(char **str, int code)
{
	*str += 1;
	if (**str == '?')
		return (exit_status(str, code));
	return (expand_pid(str));
}
