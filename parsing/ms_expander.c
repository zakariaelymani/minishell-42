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
	result = calloc(len + 1, 1);
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

