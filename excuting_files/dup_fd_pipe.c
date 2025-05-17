/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ifnot_exists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:tools/add_ifnot_exists.c
/*   Created: 2025/05/15 16:49:21 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/17 15:42:56 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
========
/*   Created: 2025/04/13 10:30:23 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/14 12:10:11 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "excute_header.h"
>>>>>>>> merged:excuting_files/dup_fd_pipe.c

void	add_var_just_not_exists(t_env **env, char *var_name, char *value)
{
	t_env	*tmp;

<<<<<<<< HEAD:tools/add_ifnot_exists.c
	if (!env | !*env)
		return ;
	tmp = (*env);
	while (tmp)
	{
		if (compare(var_name, tmp->key) == 0)
			return ;
		tmp = tmp->next;
	}
	ft_lstadd_back(env, node(ft_strjoin(var_name, value), 1));
========
	fd = open_files(cmd, env);
	if (fd == 1)
		(perror("mininshll"), exit(1));
	dup_input_output(cmd);
}
int		excute_builtins_inparent(t_cmds **cmd, t_env **env, int stat)
{
	int input;
	int	output;
	int ret_val;
	
	ret_val = open_files(cmd, env);
	if (ret_val == 1 || ret_val == -1)
	{
		if (ret_val == -1)
			excute_builtins(cmd, env, stat);
		return (1);
	}
	else if (ret_val == 0)
	{
		input = dup(STDIN_FILENO);
		output = dup(STDOUT_FILENO);
		if (input == -1 || output == -1)
			perror("minishell3");
		dup_input_output(cmd);
	}
	excute_builtins(cmd, env, stat);
	if (ret_val == 0)
	{
		if (dup2(input, STDIN_FILENO) == -1)
			perror("minishell1");
		if (dup2(output, STDOUT_FILENO) == -1)
			perror("minishell2");
		close(input);
		close(output);
	}
	return (0);
>>>>>>>> merged:excuting_files/dup_fd_pipe.c
}
