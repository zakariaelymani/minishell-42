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
	if (*s == '?')
	{
		*str += 2;
		char *temp = ft_itoa(env->exit_sta);
		return (ft_strlen(temp));
	}
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

static void	sq_mode(char **str, size_t *len)
{
	*str += 1;
	while (**str && **str != '\'')
	{
		*len += 1;
		*str += 1;
	}
	*str += 1;
}

static void	dq_mode(char **str, size_t *len, t_env *env)
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

size_t	expanded_size(char *str, t_env *env)
{
	size_t	len;

	len = 0;
	while (*str)
	{
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
