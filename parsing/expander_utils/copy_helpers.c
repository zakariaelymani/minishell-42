/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:34:43 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/14 18:34:45 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	exit_status(char *dest, char **str, int code)
{
	char	tmp[12];

	*str += 1;
	ft_cpynbr(tmp, code);
	return (ft_strlcpy(dest, tmp, ft_strlen(tmp) + 1));
}

static size_t	expand_pid(char *dest, char **str)
{
	char	tmp[12];

	*str += 1;
	ft_cpynbr(tmp, 134237);
	return (ft_strlcpy(dest, tmp, ft_strlen(tmp) + 1));
}

size_t	symbol_copy(char *dest, char **str, int code)
{
	char	*start;

	*str += 1;
	start = *str;
	if (**str == '?')
		return (exit_status(dest, str, code));
	if (**str == '$')
		return (expand_pid(dest, str));
	if (**str == '\'')
	{
		while (*++*str != '\'')
			*dest++ = **str;
		*str += 1;
	}
	else if (**str == '\"')
	{
		while (*++*str != '\"')
			*dest++ = **str;
		*str += 1;
	}
	*dest = '\0';
	return (*str - start);
}
