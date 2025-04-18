/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:53:55 by zel-yama          #+#    #+#             */
/*   Updated: 2025/01/22 10:56:43 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void executcommand(char *path, char *cmd,int input, int output)
{
	char **args;

    if(input < 0 || output < 0)
    {
        exit(2);
    }
    if(!path)
	{
		exit(3);
	}  
	dup2(input,0);
	close(input);
	dup2(output,1);
	close(output);
	args = ft_split(cmd,' ');
	execve(path ,args,NULL);
    exit(4);
}

int main(int argc, char *argv[], char *env[])
{	
	int fd;
	int pid[2];
	int n;

	pipe(pid);
	if(argc != 5)
	{
		exit(1);
	}
    n = fork(); 
    if (n == 0)
    {
        close(pid[0]);
		fd = open(argv[1],O_RDONLY);
        executcommand(find_cmdpath(env,argv[2]),argv[2],fd,pid[1]);
    }
  	else
    {
		wait(NULL);
		n = fork(); 
    	if (n == 0)
    	{
			close(pid[1]);
			fd = open(argv[4],O_WRONLY | O_CREAT | O_TRUNC,0644);
			executcommand(find_cmdpath(env,argv[3]),argv[3],pid[0],fd); 
		} 
    }
    return (0);
}
