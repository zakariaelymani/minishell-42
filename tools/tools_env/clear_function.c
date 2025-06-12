/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:12:27 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/08 09:58:34 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

void	clear_redir(t_redir **redir)
{
	t_redir	*tmp;

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
	free(*redir);
}

void	clear_commands(t_cmds **cmds)
{
	t_cmds	*tmp;

	if (!cmds || !*cmds)
		return ;
	while (*cmds)
	{
		tmp = (*cmds)->next;
		clear_redir(&(*cmds)->redirection);
		free_while((*cmds)->cmds);
		free((*cmds));
		(*cmds) = NULL;
		(*cmds) = tmp;
	}
	free(*cmds);
}

void	clear_env(t_env **env, int *last_status)
{
	t_env	*tmp;

	if (!env)
		return ;
	
	*last_status = (*env)->exit_sta;
	while (*env)
	{
		tmp = (*env)->next;
		free((*env)->value);
		(*env)->value = NULL;
		free((*env)->key);
		(*env)->key = NULL;
		free(*env);
		(*env) = tmp;
	}
	*env = NULL;
}
