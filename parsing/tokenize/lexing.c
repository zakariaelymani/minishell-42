/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:02:39 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/10 17:26:29 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_local.h"

t_token *tokenize(char *line)
{
	t_token	*tokenlist;
	int			i;
	char		*cont;

	i = -1;
	while (line[++i])
	{
		if (ft_isalpha(line[i]))
		{
			cont = get_word(&line[i]);
			ft_lstadd_back(tokenlist, ft_newtok(WORD, cont));
		}
		else if (ft_strchr("<>|", line[i]))
			add_operation_token(tokenlist, &line[i]);
		else if (ft_strchr("\'\"", line[i]))
		{
			cont = extract(&line[i]);
			ft_lstadd_back(tokenlist, ft_newtok(WORD, cont));
		}
		else if (line[i] == ' ')
			i++;
	}
	return (tokenlist);
}
