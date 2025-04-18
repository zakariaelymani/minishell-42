#ifndef  PIPEX_bonus_H
#define PIPEX_bonus_H

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>




char *findcmdpath(char **env,char *cmd);
void executcommand(char *path, char *cmd, int input, int output);
void main_here_doc(int agc, char *agv[], char *env[]);


#endif