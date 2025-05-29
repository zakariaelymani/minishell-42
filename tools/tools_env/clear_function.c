/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:12:27 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/29 12:51:33 by zel-yama         ###   ########.fr       */
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
		clear_redir(&(*cmds)->redirection);
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
	free((*env)->next);
	free(*env);
}
