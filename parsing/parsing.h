/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:42:23 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/23 17:19:26 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../minishell.h"

typedef struct s_token{
	t_type			type;
	char			*content;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

int		syntax_checker(t_token *token);
int		ms_tokappend(t_token **lst, t_token *new);
void	ms_tokclear(t_token **lst, void (*del)(void *));
void	ms_tokdelone(t_token *lst, void (*del)(void *));
void	ms_lstiter(t_token *lst, void (*f)(void *));
t_token	*ms_toklast(t_token *lst);
int		ms_toksize(t_token *lst);
t_token	*ms_tokenizer(char *line);
t_token	*ms_toknew(char *name, t_type type);
t_cmds	*ms_cmdnew(void);
void	ms_cmdappend(t_cmds **lst, t_cmds *new);
t_redir	*new_redir(t_type type);
t_cmds	*cmd_parser(t_token *tokens);
t_cmds	*ms_cmdlast(t_cmds *lst);
t_token	*ms_toklast(t_token *lst);
char	*get_word(char *pos);
int		ms_expander(t_token *tokens, t_env *env);
ssize_t	expanded_size(char *str, t_env *env);
int		fill(char *dest, char *str, t_env *env);
t_redir	*new_redir(t_type type);
t_redir	*ms_redlast(t_redir *lst);
void	ms_redappend(t_redir **lst, t_redir *new);
void	varlen(size_t *len, char *str);

#endif
