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

#include "minishell.h"

int	syntax_checker(t_token *token)
{
	size_t	i;

	i = 0;
	while (token)
	{
		if (token->type & (HEREDOC | APPEND | INPUT | OUTPUT))
			if (token->next->type != WORD)
				return (0);
		if (token->type == WORD && token->next->type == PIPE)
		{
			i = 2;
			while (token && --i)
				token = token->next;
			if (!(token->type & (WORD | HEREDOC | APPEND | INPUT | OUTPUT))
				return (0);
		}
		if (token)
			token = token->next;
	}
}
