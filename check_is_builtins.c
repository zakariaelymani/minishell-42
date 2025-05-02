/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:28:55 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/02 12:23:51 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int  check_is_builtins(t_cmds *cmd)
{
   if (compare(cmd->cmds[0], "echo") == 0)
		return (1);
	else if (compare(cmd->cmds[0], "export") == 0)
		return (2);
	else if (compare(cmd->cmds[0], "unset") == 0)
		return (3);
	else if (compare(cmd->cmds[0], "env") == 0)
		return (4);
	else if (compare(cmd->cmds[0], "pwd", 0))
		return (5)
	else if (compare(cmd->cmds[0], "exit") == 0)
		return (6);
	else if (compare(cmd->cmds[0], "cd") == 0)
		return (7);
	return (-1);
}

