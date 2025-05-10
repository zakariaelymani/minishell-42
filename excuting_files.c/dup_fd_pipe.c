/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fd_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:30:23 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/10 17:05:23 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// input i will put by default pipe if there but i chose by the function
// output and input will chose fd from this function 


void dub_for_cmds(t_cmds **cmd, t_env **env)
{
	int fd;

	fd = open_files(cmd, env);
	if (fd == 1)
		exit(1);
	dup_input_output(cmd);
}