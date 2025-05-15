/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_newcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:22:11 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/15 13:56:48 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_local.h"

t_cmds	*ms_newcmd(void)
{
	t_cmds	*result;

	result = (t_cmds *)malloc(sizeof(t_cmds));
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
