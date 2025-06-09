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

int	syntax_checker(t_token *token, t_env *env)
{
	while (token)
	{
		if (token->type == PIPE)
		{
			if (!token->prev || !token->next)
			{
				env->exit_sta = 2;
				return (ft_putstr_fd("Syntax error: Invalid pipe |\n", 2), 0);
			}
		}
		else if ((token->type & (INPUT | OUTPUT | HEREDOC | APPEND)))
		{
			if (!token->next || token->next->type != WORD)
			{
				env->exit_sta = 2;
				ft_putstr_fd("Syntax error: No redirect destination\n", 2);
				return (0);
			}
		}
		token = token->next;
	}
	return (1);
}
