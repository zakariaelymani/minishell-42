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

size_t	varsize(char *str, char **env)
{
	size_t	result;

	while (*env)
	{
		if (!ft_strncmp(*env, str + 1, (ft_strchr(*env, '=') - *env)))
		{
			result = ft_strlen(ft_strchr(*env, '=') + 1);
			return (result);
		}
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
			while (*str++ && *str != '\'')
				len++;
			len++;
		}
		else if (*str == '\"')
		{
			while (*str && *str != '\"')
			{
				if (*str == '$')
					len += varsize(&str, env);
				else
					len++''
			}
		}
		else if (*str == '$')
			len += varsize(&str, &len, env);
		else
			len++;
	}
	return (len);
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
	while (str[i])
	{
		if (str[i] == '$')
		{
			copy_from_env(result, &i, env);
			continue ;
		}
		i++;
	}
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

