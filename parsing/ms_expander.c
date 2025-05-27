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

size_t	expanded_size(char *str)
{
	size_t	len;
	int		expand;

	len = 0;
	expand = 1;
	while (*str)
	{
		if (*str == '\'')
			expand =! expand;
		if (*str == '$' && expand)
		{
			len += varsize(&str, env);
			continue;
		}
		len++;
		str++;
	}
	return (len);
}

int	expand(char *str, char **env)
{
	size_t	len;
	int		expand;
	char	*result;
	int		i;

	len = expanded_size(str);
	i = 0;
	expand = 1;
	result = malloc(len + 1);
	if (!result)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\'')
			expand =! expand;
		if (str[i] == '$' && expand)
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




