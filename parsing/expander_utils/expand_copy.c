/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:26:04 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/10 16:30:59 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	exit_status(char *dest, char **str, int code)
{
	char	tmp[12];

	*str += 2;
	ft_cpynbr(tmp, code);
	return (ft_strlcpy(dest, tmp, ft_strlen(tmp) + 1));
}

static int	special_symbol(char *dest, char **str, int code)
{
	char	*start;

	*str += 1;
	start = *str;
	if (**str == '?')
		return (exit_status(dest, str, code));
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

static int	env_cpy(char *d, char **str, t_env *env)
{
	size_t	namelen;
	char	*s;
	char	tok;

	s = *str + 1;
	if (ft_strchr("?'\"$", *s))
		return (special_symbol(d, str, env->exit_sta));
	varlen(&namelen, s);
	while (env)
	{
		tok = s[namelen];
		s[namelen] = '\0';
		if (!ft_strncmp(s, env->key, namelen + 1))
		{
			*str += namelen + 1;
			s[namelen] = tok;
			return (ft_strlcpy(d, env->value + 1, ft_strlen(env->value) + 1));
		}
		s[namelen] = tok;
		env = env->next;
	}
	while (*++*str && ft_isalnum(**str))
		;
	*d = '\0';
	return (0);
}

static void	sq_mode(char **str, char **dest)
{
	*str += 1;
	while (**str && **str != '\'')
	{
		**dest = **str;
		*str += 1;
		*dest += 1;
	}
	*str += 1;
}

static void	dq_mode(char **str, char **dest, t_env *env)
{
	*str += 1;
	while (**str && **str != '\"')
	{
		if (**str == '$' && (ft_isalnum(*(*str + 1)) || *(*str + 1) == '?'
				|| *(*str + 1) == '_' || *(*str +1) == '\'' || *(*str + 1) == '"'))
			*dest += env_cpy(*dest, str, env);
		else
		{
			**dest = **str;
			*dest += 1;
			*str += 1;
		}
	}
	*str += 1;
}

int	fill(char *dest, char *str, t_env *env)
{
	while (*str)
	{
		if (*str == '\'')
			sq_mode(&str, &dest);
		else if (*str && *str == '\"')
			dq_mode(&str, &dest, env);
		else if (*str == '$' && (ft_isalnum(*(str + 1)) || *(str + 1) == '?'
				|| *(str + 1) == '_' || *(str +1) == '\'' || *(str + 1) == '"'))
		{
			env_cpy(dest, &str, env);
			while (*dest)
			{
				if (ft_isspace(*dest))
					*dest = '\x1D';
				dest++;
			}
		}
		else
			*dest++ = *str++;
	}
	*dest = *str;
	return (0);
}
