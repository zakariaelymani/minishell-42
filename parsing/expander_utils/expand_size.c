/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:06:51 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/03 18:06:56 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	exit_status(char **str, int code)
{
	char	tmp[12];

	*str += 2;
	ft_cpynbr(tmp, code);
	return (ft_strlen(tmp));
}

ssize_t	varsize(char **str, t_env *env)
{
	size_t	namelen;
	char	*s;
	char	tok;

	namelen = 0;
	s = *str + 1;
	if (*s == '?')
		return (exit_status(str, env->exit_sta));
	varlen(&namelen, s);
	while (env)
	{
		tok = s[namelen];
		s[namelen] = '\0';
		if (!ft_strncmp(s, env->key, namelen + 1))
		{
			*str += namelen + 1;
			s[namelen] = tok;
			return ((ssize_t)ft_strlen(env->value + 1));
		}
		s[namelen] = tok;
		env = env->next;
	}
	while (*++*str && ft_isalnum(**str))
		;
	return (0);
}

static void	sq_mode(char **str, ssize_t *len)
{
	*str += 1;
	while (**str && **str != '\'')
	{
		*len += 1;
		*str += 1;
	}
	*str += 1;
}

static void	dq_mode(char **str, ssize_t *len, t_env *env)
{
	*str += 1;
	while (**str && **str != '\"')
	{
		if (**str == '$' && (ft_isalnum(*(*str + 1)) || *(*str + 1) == '?'
				|| *(*str + 1) == '_' ))
			*len += varsize(str, env);
		else
		{
			*len += 1;
			*str += 1;
		}
	}
	*str += 1;
}

ssize_t	expanded_size(char *str, t_env *env)
{
	ssize_t	len;

	len = 0;
	while (*str)
	{
		if(len > 4000000)
			return (-1);
		if (*str == '\'')
			sq_mode(&str, &len);
		else if (*str && *str == '\"')
			dq_mode(&str, &len, env);
		else if (*str == '$' && (ft_isalnum(*(str + 1)) || *(str + 1) == '?'
				|| *(str + 1) == '_'))
			len += varsize(&str, env);
		else
		{
			len++;
			str++;
		}
	}
	return (len);
}
