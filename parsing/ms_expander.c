/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:30:12 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/24 18:30:14 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
//         size_t  i;
//         size_t  len;
//
//         i = 0;
//         len = 0;
//         while (src[i])
//                 i++;
//         if (dstsize != 0)
//         {
//                 while (src[len] != '\0' && len < (dstsize - 1))
//                 {
//                         dst[len] = src[len];
//                         len++;
//                 }
//                 dst[len] = '\0';
//         }
//         return (i);
// }
//
size_t  varsize(char **str, t_env *env)
{
	size_t	namelen;
	char	*s;

	s = *str + 1;
	while (env)
	{
		namelen = ft_strlen(env->key);
		if (!ft_strncmp(env->key, s, namelen))
		{
			*str += namelen + 1;
			return (ft_strlen(env->value + 1));
		}
		env = env->next;
	}
	while (**str && !ft_strchr("\"'|>< ", **str))
		*str += 1;
	return (0);
}

size_t	expanded_size(char *str, t_env *env)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str == '\'')
		{
			str++;
			while (*str && *str != '\'')
			{
				len++;
				str++;
			}
			str++;
		}
		else if (*str && *str == '\"')
		{
			str++;
			while (*str && *str != '\"')
			{
				if (*str == '$')
					len += varsize(&str, env);
				else
				{
					len++;
					str++;
				}
			}
			str++;
		}
		else if (*str && *str == '$')
			len += varsize(&str, env);
		else
		{
			len++;
			str++;
		}
	}
	return (len);
}

int	env_cpy(char *dest, char **str, t_env *env)
{
	size_t	namelen;
	char	*s;

	s = *str + 1;
	while (env)
	{
		namelen = ft_strlen(env->key);
		if (!ft_strncmp(env->key, s, namelen))
		{
			*str += namelen + 1;
			return (ft_strlcpy(dest, env->value + 1, ft_strlen(env->value + 1) + 1));
		}
		env = env->next;
	}
	while (**str && !ft_strchr("\"'|>< ", **str))
		*str += 1;
	return (0);
}

int	fill(char *dest, char *str, t_env *env)
{
	while (*str)
	{
		if (*str == '\'')
		{
			str++;
			while (*str && *str != '\'')
				*dest++ = *str++;
			str++;
		}
		else if (*str && *str == '\"')
		{
			str++;
			while (*str && *str != '\"')
			{
				if (*str == '$')
					dest += env_cpy(dest, &str, env);
				else
					*dest++ = *str++;
			}
			str++;
		}
		else if (*str && *str == '$')
		{
			env_cpy(dest, &str, env);
			while (*dest)
			{
				if (*dest == ' ')
					*dest = '\x1F';
				dest++;
			}
		}
		else
			*dest++ = *str++;
	}
	return (0);
}

int	expand(char **str, t_env *env)
{
	size_t	len;
	char	*result;

	// if (!ft_strchr(*str, '$'))
	// 	return (0);
	len = expanded_size(*str, env);
	result = malloc(len + 1);
	if (!result)
		return (-1);
	fill(result, *str, env);
	free(*str);
	*str = result;
	return (1);
}

int	ms_expander(t_token *tokens, t_env *env)
{
	int		err;
	t_token	*head;

	head = tokens;
	while (head)
	{
		err = expand(&head->content, env);
		if (err < 0)
		{
			ft_putstr_fd("Allocation Failure", 2);
			ms_tokclear(&tokens, free);
			return (0);
		}
		head = head->next;
	}
	return (1);
}

