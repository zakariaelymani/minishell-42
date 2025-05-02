/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:25:17 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/02 12:57:44 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//this else in parent if we in bultins of in child if we in exute so what 
int		excute_builtins_inparent(t_cmds **cmd, t_env **env, int stat)
{
	int input;
	int	output;
	int ret_val;
	
	ret_val = open_files(cmd, env);
	if (ret_val == 1)
		return (1);
	else if (ret_val == -1)
		return (1);
	input = dup(STDIN_FILENO);
	output = dup(STDOUT_FILENO);
	dup_input_output(cmd);
	if (stat == 1)
		(*env)->exit_sta = my_echo((*cmd)->cmds, env);
	else if (stat == 2)
		
}


//we will do this in child not in parent so 
void excute_command(t_cmds *cmd, t_env **env)
{
	char *path;
	char **env_to_excute;

	if ()
	path = find_path_to_cmd(env, cmd->cmds[0]);
	if (!path)
		//clear and return here and exit in what in env exit status in first node and you should close fd; you should just exit; !! maybe here will be no command like this | > file.txt | no comand
	dup_input_output(cmd);
	env_to_excute = convert_strcut_array(*env);
	
	execve(path,cmd->cmds, env_to_excute);
	//here you should ` clear and / and you should run 
	
}

int	excute_command_line(t_cmds *cmd, t_env **env)
{
	int i;
	int cmdsize;

	cmdsize = t_cmdsize(cmd);
	open_files(&cmd, *env);
	if (cmdsize == 1)
	{
		i = check_is_builtins(cmd);
		if (i != -1)//excute builtins in parent 
			excute_builtins_inparent()
	}
	//now while and fork and excute and check if builtins  // child else  before you should find path or something just 
	//call fanctions and exit by his by his return not return 
	pipe_cammand(&cmd);
	i = 0;
	while (i < cmdsize)
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
			//check failure 
		if (cmd->pid == 0)
			///exute and close 
		else
			///
		i++;
	}
}
