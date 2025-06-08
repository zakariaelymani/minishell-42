/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:26:45 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/05 18:24:18 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"


void handle_parc(int i)
{
	(void)i;
	if (g_global_status == 1)
	{
		rl_on_new_line();
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
void handle_childq(int sig)
{
	(void)sig;
	safe_write(1, "Quit (core dumped)\n", 18);
	exit(131);
}

void handle_childc(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	exit(130);
}

void signals(int flag)
{
	if (flag == 1)
	{
		signal(SIGINT, handle_parc);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (flag == 2)
	{
		signal(SIGINT, handle_childc);
		signal(SIGQUIT, handle_childq);
	}
}

void heredoc_handle(int sig)
{
    if (sig == SIGINT)
    {
		write(1, "\n", 2);
        g_global_status = 3;
		//ioctl(STDIN_FILENO, FIONBIO, &arg);
		close (STDIN_FILENO);
        return ;
    }
}