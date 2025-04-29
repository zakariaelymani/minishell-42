/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:21:54 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/26 19:26:04 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void open_redir(t_redir_s **tmp)
// {
// 	if ((*tmp)->type == OUTPUT)
// 		(*tmp)->fd = ft_open((*tmp)->file_name, OUTPUT);
// 	else if (tmp->type == INPUT)
// 		(*tmp)->fd = ft_open((*tmp)->file_name, INPUT);
// 	else if ((*tmp)->type == APPEND)
// 		(*tmp)->fd = ft_open((*tmp)->file_name, APPEND);
// 	else if ((*tmp)->type == HER_DOC)
// 		(*tmp)->fd = here_document((*tmp)->file_name);
// }
// cat > c | ls | rev | grep a 
// void	pipe_cammand(t_cmds **cmd)
// {
// 	t_cmds	*tmp;
// 	int		return_val;
// 	int		pid[2];

// 	tmp = (*cmd);
// 	while (tmp->next)
// 	{
// 		return_val = pipe(pid);
// 		if (return_val == -1)
// 		{
// 			perror("pipe");
// 			exit(1);
// 		}
// 		tmp->output = pid[1];
// 		tmp->next->input = pid[0];
// 		tmp = tmp->next;
// 	}
// }

// void open_files(t_cmds **cmds)
// {
//     t_redir_s	*redir;
//     t_cmds		*tmp;
    
// 	tmp = (*cmds);
// 	redir = tmp->redirction;
// 	while (redir)
// 	{
// 		// open_redir(&redir);
// 		redir = redir->next;
// 	}
// }
