/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:37:25 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/16 16:15:25 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return (1);
	while (s[i])
	{
		if (write(fd, &s[i], 1) == -1)
			return (1);
		i++;
	}
	return (0);
}

int	check_echo_flag(char **str)
{
	int	i;
	int x;
	
	i = 1;
	if (!str[1])
		return (1);
	while (str[i])
	{
		x = 0;
		if (str[i][x] == '-' && str[i][x + 1] == 'n')
			x++;
		else
			return (i);
		while (str[i][x])
		{
			if (str[i][x] == 'n')
				x++;
			else
				return (i);
		}
		i++;	
	}
	return (i);
}
int join_and_print(int i, char **string)
{

	if (!string[i])
		return (0);
	while (string[i])
	{
		if  (write(STDOUT_FILENO, string[i], ft_strlen(string[i])) == -1)
			return (1);
		if (string[i + 1])
			if (write(STDOUT_FILENO, " ", 1) == -1)
				return (1);
		i++;
	}
	return (0);
}

int   my_echo(char **string, t_env **env)
{
	int status;
	int	i;

	(void)env;
	status = check_echo_flag(string);
	i = status;
	if (join_and_print(i, string) == 1)
		return (1);
	if (status > 1) 
		return (0);
	else if (write(1, "\n", 1) == -1)
			return (1);
	return (0);
}

