/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:53:11 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/07 21:31:10 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// void dup_that(int redir, int pipe_out)
// {
// 	dup2(redir, 1);
// 	dup2(1, pipe_out);
// }


int sheck_char(char *arg)
{
	int  i;

	i = 0;
	while (arg[i] == 32 || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if(arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
		{
			write(2, "exit\n numeric argument required\n", 33);
			return (1);
		}   
		i++;
	}
	return (0);
}


int ft_exit(char **arguments)
{
	int status;
	int i;
	
	i = 1;
	status = 0;
	if (arguments[i])
	{
		while (arguments[i])
			{
			if (sheck_char(arguments[i]) == 1)
				exit(2);
			status = norm_atoi(arguments[i]);    
			i++;
			if (arguments[i])
			{
				write(1, "exit\n minshell exit too many argumets\n",39);
				return (1);
			}
		}
	}
	if (status > 255)
	   status = status % 256; 
	write(1, "exit\n", 6);;
	exit(status);
}
