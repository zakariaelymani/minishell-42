/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:30:24 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/08 09:34:22 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	my_pwd(t_env **env)
{
	char	*pwd;
	int		fd;
	char	*line;

	line = return_value(*env, "PWD", 1);
	fd = open(".", O_WRONLY, __O_DIRECTORY, 0644);
	if (fd != -1)
		close(fd);
	pwd = getcwd(NULL, 0);
	if (!pwd && fd != -1)
		return (perror ("minishll: pwd"), 1);
	else if (!pwd || !*pwd)
	{
		if (line)
			printf("%s\n", line);
		else
			printf("%s\n", (*env)->value + 1);
	}
	else
	{
		printf("%s\n", pwd);
		free(pwd);
		pwd = NULL;
	}
	return (0);
}
