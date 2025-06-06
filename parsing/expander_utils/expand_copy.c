/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:26:04 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/03 18:26:17 by abenkaro         ###   ########.fr       */
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

static int	env_cpy(char *dest, char **str, t_env *env)
{
	size_t	namelen;
	char	*s;
	char	tok;

	s = *str + 1;
	if (*s == '?')
		return (exit_status(dest, str, env->exit_sta));
	namelen = 0;
	while (s[namelen] && (ft_isalnum(s[namelen]) || s[namelen] == '_'))
		namelen++;
	while (env)
	{
		tok = s[namelen];
		s[namelen] = '\0';
		if (!ft_strncmp(s, env->key, namelen + 1))
		{
			*str += namelen + 1;
			s[namelen] = tok;
			return (ft_strlcpy(dest, env->value + 1, ft_strlen(env->value) + 1));
		}
		s[namelen] = tok;
		env = env->next;
	}
	*str += namelen + 1;
	*dest = '\0';
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
				|| *(*str + 1) == '_'))
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
				|| *(str + 1) == '_'))
		{
			env_cpy(dest, &str, env);
			while (*dest)
			{
				if (ft_isspace(*dest))
					*dest = '\x1F';
				dest++;
			}
		}
		else
			*dest++ = *str++;
	}
	*dest = *str;
	return (0);
}
