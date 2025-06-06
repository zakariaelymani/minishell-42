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

int	expand(char **str, t_env *env)
{
	ssize_t	len;
	char	*result;

	len = expanded_size(*str, env);
	if (len < 0)
		return (-1);
	result = malloc(len + 1);
	if (!result)
		return (-2);
	fill(result, *str, env);
	free(*str);
	*str = result;
	return (1);
}

size_t	unquoted_size(char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str == '\"')
		{
			while (*++str != '\"')
				len++;
			str += 1;
		}
		else if (*str == '\'')
		{
			while (*++str != '\'')
				len++;
			str += 1;
		}
		else
		{
			str += 1;
			len++;
		}
	}
	return (len);
}

void	copy_unquoted(char *dest, char *str)
{
	while (*str)
	{
		if (*str == '\"')
		{
			while (*++str != '\"')
				*dest++ = *str;
			str += 1;
		}
		else if (*str == '\'')
		{
			while (*++str != '\'')
				*dest++ = *str;
			str += 1;
		}
		else
			*dest++ = *str++;
	}
	*dest = *str;
}

int	remove_quotes(char **str)
{
	size_t	len;
	char	*unquoted;

	len = 0;
	if (ft_strchr(*str, '"') || ft_strchr(*str, '\''))
	{
		len = unquoted_size(*str);
		unquoted = malloc(len + 1);
		if (!unquoted)
			return (-1);
		copy_unquoted(unquoted, *str);
		free(*str);
		*str = unquoted;
	}
	return (0);
}

int	ms_expander(t_token *tokens, t_env *env)
{
	int		err;
	t_token	*head;

	head = tokens;
	while (head)
	{
		if (head->prev && head->prev->type == HEREDOC)
			err = remove_quotes(&head->content);
		else
			err = expand(&head->content, env);
		if (err < 0)
		{
			if (err == -2)
				ft_putstr_fd("Allocation Failure\n", 2);
			ms_tokclear(&tokens, free);
			return (0);
		}
		head = head->next;
	}
	return (1);
}

