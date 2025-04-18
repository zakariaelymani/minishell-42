/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:53:55 by zel-yama          #+#    #+#             */
/*   Updated: 2025/01/25 13:24:48 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct t_colcter
{
	int	fd;
	int	fd2;
	int	pid[2];	
}	t_colcter;

typedef struct t_args
{
	char	**env;
	char	*args;
}	t_args;

void	free_while(char **cmd);
char	*find_cmdpath(char **env, char *cmd);
void	print_and_exit(char d);

#endif