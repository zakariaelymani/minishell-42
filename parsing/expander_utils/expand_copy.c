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

#include "../parsing.h"

static int	env_cpy(char *d, char **str, t_env *env)
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

static void	sq_mode(char **str, char **dest)
{
	*(*dest)++ = *(*str)++;
	while (**str && **str != '\'')
	{
		**dest = **str;
		*str += 1;
		*dest += 1;
	}
	*(*dest)++ = *(*str)++;
}

static void	dq_mode(char **str, char **dest, t_env *env)
{
	*(*dest)++ = *(*str)++;
	while (**str && **str != '\"')
	{
		if (**str == '$' && *(*str + 1) != '\"' && (ft_isalnum(*(*str + 1))
				|| special_delim(*(*str + 1))))
		{
			env_cpy(*dest, str, env);
			while (**dest)
			{
				if (**dest == '"' || **dest == '\'')
					**dest = **dest * -1;
				*dest += 1;
			}
		}
		else
			*(*dest)++ = *(*str)++;
	}
	*(*dest)++ = *(*str)++;
}

void	preserve_sq(char **dest)
{
	while (**dest)
	{
		if (ft_isspace(**dest))
		{
			if (**dest == ' ')
				**dest = '\x1D';
			else
				**dest = '\x1E';
		}
		else if (**dest == '"' || **dest == '\'')
			**dest = **dest * -1;
		*dest += 1;
	}
}

int	fill(char *dest, char *str, t_env *env)
{
	while (*str)
	{
		if (*str == '$' && (*(str + 1) == '"' || *(str + 1) == '\''))
			str++;
		else if (*str == '\'')
			sq_mode(&str, &dest);
		else if (*str && *str == '\"')
			dq_mode(&str, &dest, env);
		else if (*str == '$' && (ft_isalnum(*(str + 1))
				|| special_delim(*(str + 1))))
		{
			env_cpy(dest, &str, env);
			preserve_sq(&dest);
		}
		else
			*dest++ = *str++;
	}
	*dest = *str;
	return (0);
}
