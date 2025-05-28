/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:26:45 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/28 15:11:57 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"


void handler(int i)
{
	if (i == SIGINT && g_global_status == 1)
	{
		rl_on_new_line();
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (i == SIGQUIT && g_global_status == 1)
	{
		rl_replace_line("" ,0);
		rl_redisplay();
	}
}


void handler_child(int sig)
{
	if (SIGINT == sig)
	{
		write(2, "\n", 1);
		exit(130);
	}
	else if (SIGQUIT == sig)
	{
		write(2, "Quit (core dumped)\n", 20);
		exit(131);
	}
}

void signales(int flag)
{
	if (flag == 1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
	}
	else if (flag == 2)
	{
		signal(SIGINT, handler_child);
		signal(SIGQUIT, handler_child);
	}
}

void heredoc_handle(int sig)
{
    if (sig == SIGINT)
    {
		write(1, "\n", 2);
        g_global_status = 3;
        close(STDIN_FILENO);
        return ;
    }
}