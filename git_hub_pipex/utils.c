/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:42:08 by zel-yama          #+#    #+#             */
/*   Updated: 2025/01/22 10:42:33 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


char	*free_and_join(char *store, char *s)
{
	char	*str;

	str = ft_strjoin(store, s);
	free(store);
	store = NULL;
	return (str);
}
char *findPATH(char **env)
{
    char *path;
    int i;
    int y;
    i = 0;
    
    path = "PATH=";
    y = 0;
    while(env[i] && path[y])
    {
       
        y = 0;
        while(path[y])
        {
            if (path[y] == env[i][y])
            {
                y++;
            }
            else 
                break ;
        }
        i++;
    }
    return (env[i - 1]);
}
int check_spialcharac(char *s)
{
    int i;
    
    i = 0;
    while(s[i])
    {
        if (ft_isalpha(s[i]) == 0)
            return(0);
        i++;
    }
    return (1);
}
char *find_cmdpath(char **env,char *cmd)
{
    char *path;
    char *cmdjoined;
    char **splited;
    char **cmds;
    int i;
    int check;

    i = 0;
    cmds = ft_split(cmd, ' ');
    cmd  = cmds[0];
    if(check_spialcharac(cmds[0]) == 0) 
        return (NULL);
    path = findPATH(env);
    path = ft_strchr(path,'/');
    splited = ft_split(path,':');
    cmd = ft_strjoin("/",cmd); 
    while(splited[i])
    {
        cmdjoined = ft_strjoin(splited[i], cmd);
        check = access(cmdjoined, F_OK | X_OK);
        if (check == 0)
            return (cmdjoined);
       i++;
    }
    return (NULL);
}
