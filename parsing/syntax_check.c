/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:10:27 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/17 17:21:16 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	syntax_checker(t_token *token)
{
	size_t	i;

	i = 0;
	while (token)
	{
		if (token->type == PIPE)
		{
			if (!token->prev || !token->next)
				return (printf("INVALID SYNTAX NEAR : %s\n", token->content), 0);
		}
		else if (token-> type & (INPUT | OUTPUT | HEREDOC | APPEND))
			if (!token->next || token->next->type != WORD || !(*token->next->content))
				return (printf("INVALID SYNTAX NEAR : %s\n", token->content), 0);
		token = token->next;
	}
	return (1);
}
