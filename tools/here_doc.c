/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:07:40 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/09 15:12:35 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	read_conten(char *limiter, int fd, t_env *env, int flag)
{
	char	*line;
	int		i;

	(1) && (line = NULL, i = 0);
	while (1)
	{
		(signal(SIGINT, heredoc_handle), signal(SIGQUIT, SIG_IGN));
		line = readline(">");
		if (g_global_status == 3)
			return (close(fd), free(line), -2);
		if (!line)
			return (write(2, "Delimiter not specified\n", 25), fd);
		line = free_and_join(line, "\n", 1);
		if (flag == -2)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)))
				expand(&line, env, 1);
		}
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			return (free(line), fd);
		else
			ft_putstr_fd(line, fd);
		(1) && (free(line), line = NULL);
	}
	return (fd);
}

char	*randomize_name(int fd)
{
	char	*name;
	char	*return_val;
	int		name_int;

	name_int = (long)&fd;
	name = ft_itoa(name_int);
	return_val = ft_strjoin("/tmp/", name);
	return (free(name), name = NULL, return_val);
}

int	here_document(char *limiter, int flag, t_env **env)
{
	int		fd;
	int		fd_input;
	char	*name;

	name = randomize_name(0);
	fd = ft_open(name, OUTPUT);
	fd_input = ft_open(name, INPUT);
	unlink(name);
	limiter = free_and_join(limiter, "\n", 0);
	fd = read_conten(limiter, fd, *env, flag);
	if (fd > -1)
		close(fd);
	free(limiter);
	if (fd == -2)
		(*env)->exit_sta = 130;
	if (fd == -2 || fd == -1)
		return (unlink(name), free(name), close(fd_input), -2);
	free(name);
	name = NULL;
	(*env)->exit_sta = 0;
	return (fd_input);
}
