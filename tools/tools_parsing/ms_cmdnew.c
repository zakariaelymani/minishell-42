/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmdnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:22:11 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/10 16:31:22 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmds	*ms_cmdnew(void)
{
	t_cmds	*result;

	result = (t_cmds *)ft_malloc(sizeof(t_cmds));
	if (!result)
		return (NULL);
	result->cmds = NULL;
	result->input = -1;
	result->output = -1;
	result->pid = -1;
	result->redirection = NULL;
	result->next = NULL;
	return (result);
}
