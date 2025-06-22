/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_hd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:26:02 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/22 18:26:03 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static ssize_t	varsize_hd(char **str, t_env *env)
{
	size_t	namelen;
	char	*s;

	namelen = 0;
	s = *str + 1;
	if (special_delim(*s) && *s != '_')
		return (symbol_size(str, env->exit_sta));
	varlen(&namelen, s);
	while (env)
	{
		if (key_found(s, env->key, namelen))
		{
			*str += namelen + 1;
			if (!env->value)
				return (0);
			return ((ssize_t)ft_strlen(env->value + 1));
		}
		env = env->next;
	}
	while (*++*str && (ft_isalnum(**str) || **str == '_'))
		;
	return (0);
}

ssize_t	expanded_size_hd(char *str, t_env *env)
{
	ssize_t	len;

	len = 0;
	while (*str)
	{
		if (len > 4000000)
			return (-1);
		if (*str == '$' && (*(str + 1) == '"' || *(str + 1) == '\''))
		{
			len++;
			str++;
		}
		else if (*str == '$' && (ft_isalnum(*(str + 1))
				|| special_delim(*(str + 1))))
			len += varsize_hd(&str, env);
		else
		{
			len++;
			str++;
		}
	}
	return (len);
}

static int	env_cpy_hd(char *d, char **str, t_env *env)
{
	size_t	namelen;
	char	*s;

	s = *str + 1;
	if (special_delim(*s) && *s != '_')
		return (symbol_copy(d, str, env->exit_sta));
	varlen(&namelen, s);
	while (env)
	{
		if (key_found(s, env->key, namelen))
		{
			*str += namelen + 1;
			if (!env->value)
				return (ft_strlcpy(d, "\0", 1));
			return (ft_strlcpy(d, env->value + 1, ft_strlen(env->value) + 1));
		}
		env = env->next;
	}
	while (*++*str && (ft_isalnum(**str) || **str == '_'))
		;
	*d = '\0';
	return (0);
}

int	fill_hd(char *dest, char *str, t_env *env)
{
	while (*str)
	{
		if (*str == '$' && (*(str + 1) == '"' || *(str + 1) == '\''))
			*dest++ = *str++;
		else if (*str == '$' && (ft_isalnum(*(str + 1))
				|| special_delim(*(str + 1))))
			dest += env_cpy_hd(dest, &str, env);
		else
			*dest++ = *str++;
	}
	*dest = *str;
	return (0);
}
