/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:10:27 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/10 16:31:16 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	syntax_checker(t_token *token)
{
	while (token)
	{
		if (token->type == PIPE)
		{
			if (!token->prev || !token->next)
				return (ft_putstr_fd("Syntax error: Invalid pipe |\n", 2), 0);
		}
		else if ((token->type & (INPUT | OUTPUT | HEREDOC | APPEND)))
		{
			if (!token->next || token->next->type != WORD)
			{
				ft_putstr_fd("Syntax error: No redirect destination\n", 2);
				return (0);
			}
		}
		token = token->next;
	}
	return (1);
}
