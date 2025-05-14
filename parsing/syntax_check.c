/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:02:50 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/14 18:10:19 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_local.h"

int	syntax_check(t_token *token)
{
	while (tokenlist)
	{
		if (token->type == HEREDOC || token->type == APPEND || token->type == INPUT || token->type == OUTPUT)
			if (token->next->type != WORD)
				return(ft_putendl_fd("SYNTAX ERROR"), 1);
		else if (token->type == 
	}
}
