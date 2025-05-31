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
size_t  varsize(char **str, char **env)
{
	size_t	namelen;
	char	*s;

	s = *str + 1;
	while (*env)
	{
		namelen = ft_strchr(*env, '=') - *env;
		if (!ft_strncmp(s, *env, namelen))
		{
			*str += namelen + 1;
			return (ft_strlen(ft_strchr(*env, '=') + 1));
		}
		env++;
	}
	while (**str && !ft_strchr("\"'|>< ", **str))
		*str += 1;
	return (1);
}

size_t	expanded_size(char *str, char **env)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str == '\'')
		{
			len++;
			while (*++str && *str != '\'')
				len++;
		}
		else if (*str && *str == '\"')
		{
			len++;
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

int	env_cpy(char *dest, char **str, char **env)
{
	size_t	namelen;
	char	*s;

	s = *str + 1;
	while (*env)
	{
		namelen = ft_strchr(*env, '=') - *env;
		if (!ft_strncmp(s, *env, namelen))
		{
			*str += namelen + 1;
			return (ft_strlcpy(dest, ft_strchr(*env, '=') + 1, strlen(*env) - namelen));
		}
		env++;
	}
	while (**str && !ft_strchr("\"'|>< ", **str))
		*str += 1;
	return (0);
}

int	fill(char *dest, char *str, char **env)
{
	char	*head;

	head = str;
	while (*str)
	{
		if (*str == '\'')
		{
			*dest++ = *str++;
			while (*str && *str != '\'')
				*dest++ = *str++;
		}
		else if (*str && *str == '\"')
		{
			*dest++ = *str++;
			while (*str && *str != '\"')
			{
				if (*str == '$')
					dest += env_cpy(dest, &str, env);
				else
					*dest++ = *str++;
			}
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

int	expand(char **str, char **env)
{
	size_t	len;
	char	*result;
	int		i;

	if (!ft_strchr(*str, '$'))
		return (0);
	len = expanded_size(*str, env);
	i = 0;
	result = malloc(len + 1);
	if (!result)
		return (-1);
	fill(result, *str, env);
	free(*str);
	*str = result;
	return (1);
}

int	ms_expander(t_token *tokens, char **env)
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

