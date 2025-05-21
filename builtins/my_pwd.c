/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:30:24 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/20 12:17:54 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int my_pwd(t_env **env)
{
	char	*pwd;
	int		fd;
	char	*line;

	line = return_value(*env, "PWD");
	fd = open(".", O_WRONLY,  __O_DIRECTORY, 0644);
	close(fd);
	pwd = getcwd(NULL, 0);
	if (!pwd  && fd != -1)
		return (perror ("minishll: pwd"), 1);
	else if (!pwd || !*pwd)
	{
		if (line)
			printf("%s\n", return_value(*env, "PWD"));
	}
	else
	{
		printf("%s\n", pwd);
		free(pwd);
		pwd = NULL;
	}
	return (0);
}
