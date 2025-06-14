/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:30:12 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/10 16:31:08 by abenkaro         ###   ########.fr       */
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
	result = ft_malloc(len + 1);
	if (!result)
		return (-2);
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
		if (head->prev && head->prev->type == HEREDOC)
			err = heredoc_quotes(&head->content);
		else
		{
			err = expand(&head->content, env);
			if (head ->prev && (head->prev->type & (APPEND | INPUT | OUTPUT)))
				remove_quotes(&head->content);
		}
		if (err < 0)
		{
			if (err == -2)
				ft_putstr_fd("Allocation Failure\n", 2);
			else
				ft_putstr_fd("##Input is too big## unset large env var\n", 2);
			return (0);
		}
		head = head->next;
	}
	return (1);
}
