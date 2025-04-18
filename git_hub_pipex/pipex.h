#ifndef  PIPEX_H
#define PIPEX_H

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>




char *find_cmdpath(char **env,char *cmd);


#endif