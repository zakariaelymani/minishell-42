/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:14:11 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/09 14:49:24 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	handle_parc(int i)
{
	(void)i;
	if (g_global_status == 1 || g_global_status == 4)
	{
		g_global_status = 4;
		rl_on_new_line();
		safe_write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signals(int flag)
{
	if (flag == 1)
	{
		signal(SIGINT, handle_parc);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (flag == 2)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}
 
void	heredoc_handle(int sig)
{
	if (sig == SIGINT)
	{
		g_global_status = 3;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		return ;
	}
}

int	handle_sigs_child(t_env **env, int status)
{
	if (status == 2)
	{
		safe_write(1, "\n", 1);
		(*env)->exit_sta = 130;
	}
	else if (status == 3)
	{
		safe_write(1, "Quit (core dumped)\b\n", 21);
		(*env)->exit_sta = 131;
	}
	return (1);
}
