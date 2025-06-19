/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:06:51 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/10 16:31:00 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

ssize_t	varsize(char **str, t_env *env)
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

static void	sq_mode(char **str, ssize_t *len)
{
	*str += 1;
	*len += 1;
	while (**str && **str != '\'')
	{
		*str += 1;
		*len += 1;
	}
	*len += 1;
	*str += 1;
}

static void	dq_mode(char **str, ssize_t *len, t_env *env)
{
	*str += 1;
	*len += 1;
	while (**str && **str != '\"')
	{
		if (**str == '$' && *(*str + 1) != '\"' && (ft_isalnum(*(*str + 1))
				|| special_delim(*(*str + 1))))
			*len += varsize(str, env);
		else
		{
			*len += 1;
			*str += 1;
		}
	}
	*len += 1;
	*str += 1;
}

ssize_t	expanded_size(char *str, t_env *env)
{
	ssize_t	len;

	len = 0;

	while (*str)
	{
		if (*str == '$' && (*(str + 1) == '"' || *(str + 1) == '\''))
		{
			str++;
			continue;
		}
		if (len > 4000000)
			return (-1);
		if (*str == '\'')
			sq_mode(&str, &len);
		else if (*str && *str == '\"')
			dq_mode(&str, &len, env);
		else if (*str == '$' && (ft_isalnum(*(str + 1))
				|| special_delim(*(str + 1))))
			len += varsize(&str, env);
		else
		{
			len++;
			str++;
		}
	}
	return (len);
}
