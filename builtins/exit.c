/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:53:11 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/28 14:33:02 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"


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
			while (arg[i] == 32 || (arg[i] >= 9 && arg[i] <= 13))
				i++;
			if (!arg[i])
				return (0);
			write(2, "minishell :exit: numeric argument required \n", 45);
			return (1);
		}   
		i++;
	}
	return (0);
}


int ft_exit(char **arguments, long status)
{
	int i;
	int sing;

	(1) && (sing = 0, i = 1);
	if (arguments[i])
	{
		while (arguments[i])
		{
			if (sheck_char(arguments[i]) == 1)
				exit(2);
			status = norm_atoi(arguments[i], 0, &sing);    
			i++;
			if (arguments[i])
			{
				safe_write(2, "exit\n minshell too many argumets\n", 34);
				return (1);
			}	
		}
	}
	if (status > 255)
	   status = status % 256;
	write(1, "exit\n", 6);
	if (sing  == -1)
		safe_write(2,"minishell: exit: numeric argument required\n", 43);
	exit(status);
}
