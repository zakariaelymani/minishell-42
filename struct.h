/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:46:34 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/08 10:05:19 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_env
{
	int				status;
	int				exit_sta;
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef enum e_type{
	WORD = 1 << 0,
	APPEND = 1 << 1,
	HEREDOC = 1 << 2,
	INPUT = 1 << 3,
	OUTPUT = 1 << 4,
	PIPE = 1 << 5,
	NONE = 1 << 6,
}	t_type;

typedef struct s_redir
{
	char			*file_name;
	t_type			type;
	int				fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmds
{
	char				**cmds;
	int					input;
	int					output;
	pid_t				pid;
	t_redir				*redirection;
	struct s_cmds		*next;
}	t_cmds;

#endif
