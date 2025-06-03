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

size_t  varsize(char **str, t_env *env)
{
	size_t	namelen;
	char	*s;

	namelen = 0;
	s = *str + 1;
	while (s[namelen] && ft_isalnum(s[namelen]))
		namelen++;
	while (env)
	{
		namelen = ft_strlen(env->key);
		if (!ft_strncmp(s, env->key, namelen))
		{
			*str += namelen + 1;
			return (ft_strlen(env->value + 1));
		}
		env = env->next;
	}
	(*str)++;
	while (**str && ft_isalnum(**str))
		*str += 1;
	return (0);
}

static int	sq_mode(char **str, ssize_t *len)
{
	*str += 1;
	while (**str && **str != '\'')
	{
		*len += 1;
		*str += 1;
	}
	if (**str == '\0')
		return (-1);
	*str += 1;
	return (0);
}

static int	dq_mode(char **str, ssize_t *len, t_env *env)
{
	*str += 1;
	while (**str && **str != '\"')
	{
		if (**str == '$' && ft_isalnum(*(*str + 1)))
			*len += varsize(str, env);
		else
		{
			*len += 1;
			*str += 1;
		}
	}
	if (**str == '\0')
		return (-1);
	*str += 1;
	return (0);
}

ssize_t	expanded_size(char *str, t_env *env)
{
	ssize_t	len;

	len = 0;
	while (*str)
	{
		if (*str == '\'')
		{
			if (sq_mode(&str, &len) < 0)
				return (-1);
		}
		else if (*str && *str == '\"')
		{
			if (dq_mode(&str, &len, env) < 0)
				return (-1);
		}
		else if (*str == '$' && ft_isalnum(*(str + 1)))
			len += varsize(&str, env);
		else
		{
			len++;
			str++;
		}
	}
	return (len);
}
