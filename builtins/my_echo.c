/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:37:25 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/08 09:14:08 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_echo_flag(char **str)
{
	int	i;
	int	x;

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

char	*join_strings(int i, char **string, int flag)
{
	char	*line;
	char	*prev;
	char	*store;

	(1) && (prev = NULL, store = NULL);
	if (!string[i] && i == 1)
		return (write(1, "\n", 2), NULL);
	else if (!string[i] && i != 1)
		return (NULL);
	while (string[i])
	{
		if (!string[i + 1])
		{
			prev = free_and_join(prev, string[i], 1);
			break ;
		}
		line = free_and_join(string[i], " ", 0);
		free_vars(store, NULL, NULL, NULL);
		store = line;
		prev = free_and_join(prev, line, 1);
		i++;
	}
	if (flag == 1)
		prev = free_and_join(prev, "\n", 1);
	return (prev);
}

int	my_echo(char **strings, t_env **env)
{
	int		status;
	int		i;
	char	*line;

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
