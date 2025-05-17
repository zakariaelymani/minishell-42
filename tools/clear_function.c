/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:12:27 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/17 15:49:37 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	clear_redir(t_redir_s **redir)
{
	t_redir_s	*tmp;

	if (!redir || !*redir)
		return ;
	while (*redir)
	{
		tmp = (*redir)->next;
		free((*redir)->file_name);
		(*redir)->file_name = NULL;
		free(*redir);
		(*redir) = NULL;
		*redir = tmp;
	}
}

void	clear_commands(t_cmds **cmds)
{
	t_cmds	*tmp;

	if (!cmds || !*cmds)
		return ;
	while (*cmds)
	{
		tmp = (*cmds)->next;
		free_while((*cmds)->cmds);
		clear_redir(&(*cmds)->redirction);
		free((*cmds));
		(*cmds) = NULL;
		(*cmds) = tmp;
	}
}

void	clear_env(t_env **env)
{
	t_env	*tmp;

	if (!env || !*env)
		return ;
	rl_clear_history();
	while (*env)
	{
		if ((*env)->next)
			tmp = (*env)->next;
		else
			return ;
		free((*env)->value);
		(*env)->value = NULL;
		free((*env)->key);
		(*env)->key = NULL;
		free(*env);
		*env = NULL;
		(*env) = tmp;
	}
}
