/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:37:25 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/02 14:05:46 by zel-yama         ###   ########.fr       */
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


char *join_strings(int i, char **string, int flag)
{
	char	*line;
	char	*prev;
	char	*store;

	prev = NULL;
	store = NULL;
	if (!string[i])
		return (NULL);
	while (string[i])
	{
		if (!string[i + 1])
		{
			prev = free_and_join(prev, string[i], 1);
			break;
		}
		line = free_and_join(string[i], " ", 0);
		free_vars(store, NULL, NULL, NULL);
		store = line;
		prev = free_and_join(prev, line, 1);//maybe leaks
		i++;
	}
	if (flag == 1)
		prev = free_and_join(prev, "\n", 1);
	return (prev);
}

int   my_echo(char **strings, t_env **env)
{
	int 	status;
	int		i;
	char 	*line;

	(void)env;
	status = check_echo_flag(strings);
	i = status;

	line = join_strings(i, strings, status);
	if (line)
	{
		safe_write(1, line, ft_strlen(line));
		free(line);
	}
	return (0);
}

