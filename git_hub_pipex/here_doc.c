#include "pipex_bonus.h"

char *is_thathere(char *s, char c)
{
	int i;

	i = 0;
	if(!s)
		return (NULL);
	while(s[i] != c)
	{
		if(!s[i])
			return (NULL);
		i++;
	}
	return (s);
}
char	*free_and_join(char *store, char *s)
{
	char	*str;

	str = ft_strjoin(store, s);
	free(store);
	store = NULL;
	return (str);
}
void here_doc(char *limitter)
{
	char buffer[1111];
	int fd;
	char *tmp;
	ssize_t readbitys;

	limitter = ft_strjoin(limitter, "\n");
	fd = open("/tmp/here_doc.txt", O_WRONLY | O_CREAT | O_TRUNC , 0644);
	while (1)
	{
		ft_putstr_fd("pipe pipe heredoc>",1);
		tmp = NULL;
		while(is_thathere(tmp,'\n') == NULL)
		{
			readbitys = read(1,buffer,1);
			buffer[readbitys] = '\0';
			if(readbitys == -1)
				exit(7);
			tmp = free_and_join(tmp,buffer);
		}
		if (ft_strncmp(tmp,limitter, ft_strlen(limitter)) == 0)
			break;
		else
			ft_putstr_fd(tmp,fd);
	}
	free(tmp);
}
void main_here_doc(int agc, char *agv[], char *env[])
{
	int forfork;
	int pid[2];
	int fd;
	int fd2;
	
	pipe(pid);
	forfork = fork();
	if (agc != 6)
	{
		ft_putstr_fd("not valid arguments",2);
		exit(1);
	}
	if (forfork == 0)
	{
		close(pid[0]);
		here_doc(agv[2]);
		fd = open("here_doc.txt", O_RDONLY,0644);
		executcommand(findcmdpath(env, agv[3]),agv[3], fd, pid[1]);
	}
	else
	{
		wait(NULL);
		unlink("/tmp/here_doc");
		close(pid[1]);
		fd2 = open(agv[5],O_WRONLY | O_CREAT | O_APPEND, 0644);
		executcommand(findcmdpath(env,agv[4]), agv[4], pid[0],fd2);
	}
}
