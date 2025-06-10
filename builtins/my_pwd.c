/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:30:24 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/09 11:50:53 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	my_pwd(t_env **env)
{
	char	*pwd;
	int		fd;

	if (!*((*env)->value + 1))
		return (perror("minishell you run minishell in unexisted dir"), 1);
	fd = open(".", O_WRONLY, __O_DIRECTORY, 0644);
	if (fd != -1)
		close(fd);
	pwd = getcwd(NULL, 0);
	if (!pwd && fd != -1)
		return (perror ("minishll: pwd"), 1);
	else if (!pwd || !*pwd)
	{
		printf("%s\n", (*env)->value + 1);
	}
	else
		printf("%s\n", pwd);
	free_vars(pwd, NULL, NULL, NULL);
	return (0);
}
