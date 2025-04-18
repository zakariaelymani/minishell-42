#include "pipex_bonus.h"

void executcommand(char *path, char *cmd,int input, int output)
{
	char **agrs;
    int forfork;
    if(input < 0 || output < 0)
    {
        perror("error in");
        exit(1);
    }
    forfork = fork();
    if (forfork == 0)
    {
        dup2(input,0);
        close(input);
        dup2(output,1);
        close(output);
        if (!path)
        {
            perror("command not found");
            exit(1);
        }
        agrs = ft_split(cmd,' ');
        execve(path ,agrs,NULL);
        perror("error in execve function");
        exit(1);
    }
    else
	{
		wait(NULL);
		close(input);
		close(output);
	}	
}

int main(int argc, char *argv[], char *env[])
{	
	int pid[argc - 3][2];
	int i;
	int j;
	int fd;
	int k = 0;

	j = 0;
	
	if (ft_strncmp(argv[1], "here_doc",ft_strlen("here_doc")) == 0)
	{
		main_here_doc(argc, argv, env);
		return (0);
	}
	i = argc - 3;
	while(k < argc)
	{
		pipe(pid[k]);
		k++;
	}
	while(j < i)
	{
		if(j == 0)
		{
			fd = open(argv[1],O_RDONLY);
			executcommand(findcmdpath(env,argv[2]),argv[2],fd,pid[ j + 1][1]);
			j++;
		}
		else if(j + 1 == i)
		{
			fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,0644);
			executcommand(findcmdpath(env,argv[j + 2]),argv[j + 2],pid[j][0],fd);
			j++;
		}
		else {
			executcommand(findcmdpath(env,argv[ j + 2]), argv[ j + 2],pid[j][0],pid[j + 1][1]);
			j++;
		}	
	}  
	j = 0;
	while(j < argc - 3)
	{
		 i = 0;
		while (i < 2)
		{
			close(pid[j][i]);
			i++;
		}
		j++;
	}
    return (0);
}
