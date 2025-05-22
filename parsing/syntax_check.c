/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:10:27 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/22 16:07:24 by abenkaro         ###   ########.fr       */
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
				return (printf("INVALID SYNTAX NEAR : %s\n", token->content), 0);
		}
		else if ((token->type & (INPUT | OUTPUT | HEREDOC | APPEND)))
			if (!token->next)
				return (printf("INVALID SYNTAX NEAR : %s\n", token->content), 0);
		token = token->next;
	}
	return (1);
}
