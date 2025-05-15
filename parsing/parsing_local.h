/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_local.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:42:23 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/14 14:14:48 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_LOCAL_H
#define PARSING_LOCAL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "../minishell.h"

typedef struct s_token{
	t_type	 		type;
	char			*content;
	struct s_token	*next;
}	t_token;

void ms_lstadd_back(t_token **lst, t_token *new);
void ms_lstadd_front(t_token **lst, t_token *new);
void ms_lstclear(t_token **lst, void (*del)(void *));
void ms_lstdelone(t_token *lst, void (*del)(void *));
void ms_lstiter(t_token *lst, void (*f)(void *));
t_token *ms_lstlast(t_token *lst);
t_token *ms_lstmap(t_token *lst, void *(*f)(void *), void (*del)(void *));
int ms_lstsize(t_token *lst);
t_token *ms_tokenizer(char *line);
t_token *ms_newtoken(char *name, t_type type);
t_cmds	*ms_newcmd(void);
void    ms_appendcmd(t_cmds **lst, t_cmds *new);
t_redir	*new_redir(t_type type);
t_cmds	*cmd_parser(t_token *tokens);
void    ms_appendcmd(t_cmds **lst, t_cmds *new);
t_cmds	*ms_cmdlast(t_cmds *lst);

#endif
