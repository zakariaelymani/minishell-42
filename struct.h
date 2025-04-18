/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:46:34 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/18 19:45:19 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_env
{
    int status;
    char *key;
    char *value;
    struct s_env *next;
    
}   t_env;

//this redirction  type 
typedef enum  s_redir
{
    INPUT,
    OUTPUT,
    APPEND,
    HER_DOC,
    
}   t_redir;
// this  cammands type output input
typedef enum s_cmd 
{
    PIPE,
    REDIR,
    NOT,
	HER_DOC,
	MIXED,
}	t_cmd;
typedef struct s_redir_strcut
{
	char *file_name; // if here_doc   this well be limiter 
	t_redir type; //<< >> < > 
	int 	fd;/// this form my work don't touch this 
	struct  s_redir_struct *next;
}	t_redir_s;

typedef struct s_cmds
{
    char 		**cmps ;//command with arguments;
	int			input;
	int 		output;//this for me 
	t_cmd		enum_cmd;//this form what is in front of the command
	t_redir_s 	*redirction;//this put strcut to  s
	struct		s_cmds *next;
}	t_cmds;

#endif