/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:53:55 by zel-yama          #+#    #+#             */
/*   Updated: 2025/01/25 15:19:42 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_while(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix[0])
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
}

void	close_file(t_colcter hlder)
{
	int	i;

	if (hlder.fd >= 0)
		close(hlder.fd);
	if (hlder.fd2 >= 0)
		close(hlder.fd2);
	i = 0;
	while (i < 2)
	{
		close(hlder.pid[i]);
		i++;
	}
}

void	executcommand(t_args argumens, int input,
	int output, t_colcter filehoder)
{
	char	**cmd;
	char	*path;

	path = find_cmdpath(argumens.env, argumens.args);
	if (!path)
		(close_file(filehoder), print_and_exit('c'));
	cmd = ft_split(argumens.args, ' ');
	dup2(input, 0);
	close(input);
	dup2(output, 1);
	close(output);
	execve(path, cmd, NULL);
	free(path);
	free_while(cmd);
	close_file(filehoder);
	print_and_exit('x');
}

void	forkand_excute(t_args argumens, int input,
	int output, t_colcter filecolcter)
{
	int		forfork;

	forfork = fork();
	if (forfork == -1)
		(close_file(filecolcter), print_and_exit('d'));
	if (forfork == 0)
	{
		executcommand(argumens, input, output, filecolcter);
	}
	else
	{
		if (wait(NULL) == -1)
			(close_file(filecolcter), print_and_exit('w'));
		close(input);
		close(output);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_colcter	holder;
	t_args		arguments;

	if (!env)
		print_and_exit('e');
	if (argc != 5)
		print_and_exit('r');
	if (pipe(holder.pid) == -1)
		(print_and_exit('p'));
	holder.fd = open(argv[1], O_RDONLY, 0644);
	holder.fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (holder.fd < 0 || holder.fd2 < 0)
		(close_file(holder), print_and_exit('f'));
	arguments.args = argv[2];
	arguments.env = env;
	forkand_excute(arguments, holder.fd, holder.pid[1], holder);
	arguments.args = argv[3];
	forkand_excute(arguments, holder.pid[0], holder.fd2, holder);
	return (0);
}
