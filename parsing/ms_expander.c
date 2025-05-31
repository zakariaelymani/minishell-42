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

size_t  varsize(char **str, char **env)
{
	size_t	namelen;
	char	*s;

	s = *str + 1;
	while (*env)
	{
		namelen = strchr(*env, '=') - *env;
		if (!strncmp(s, *env, namelen))
		{
			*str += namelen + 1;
			return (strlen(strchr(*env, '=') + 1));
		}
		env++;
	}
	return (0);
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
		namelen = strchr(*env, '=') - *env;
		if (!strncmp(s, *env, namelen))
		{
			*str += namelen + 1;
			return (strlcpy(dest, strchr(*env, '=') + 1), namelen);
		}
		env++;
	}
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
			while (*++str && *str != '\'')
				*dest++ = *str;
		}
		else if (*str && *str == '\"')
		{
			len++;
			str++;
			*dest++ = *str++;
			while (*str && *str != '\"')
			{
				if (*str == '$')
					env_cpy(dest, &str, env);
				else
					*dest++ = *str++;
			}
		}
		else if (*str && *str == '$')
			envcpy(dest, &str, env);
		else
			*dest++ = *str++;
	}
	return (0);
}

int	expand(char *str, char **env)
{
	size_t	len;
	char	*result;
	int		i;

	len = expanded_size(str, env);
	i = 0;
	result = malloc(len + 1);
	if (!result)
		return (-1);
	free(str);
	str = result;
	return (1);
}

int	ms_expander(t_token *tokens, char **env)
{
	int		err;
	t_token	*head;

	head = tokens;
	while (head)
	{
		head = head->next;
		err = expand(head->content, env);
		if (err < 0)
		{
			ft_putstr_fd("Allocation Failure", 2);
			ms_tokclear(tokens);
			return (0);
		}
	}
	return (1);
}

