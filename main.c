/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:30:23 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 15:26:19 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void check_line(char *line, t_env *env)
{
	char **splited;
	int		i;
	
	i = 0;
	splited = ft_split(line, ' ');
	while (splited[i])
	{
		if (ft_strncmp("cd", splited[i] , 2) == 0 && ft_strlen(splited[i]) == 2)
			change_dir(splited[i + 1], &env);
		else if (ft_strncmp("export", splited[i], 6) == 0 && ft_strlen(splited[i]) == 6)
			export(&env, splited[i + 1]);
		else if (ft_strncmp("env", splited[i], 3) == 0 && ft_strlen(splited[i]) == 3)
			env_cmd(&env);
		else if (ft_strncmp("exit", splited[i], 4) == 0 && ft_strlen(splited[i]) == 4)
			ft_exit(splited[i]);
		else if (ft_strncmp("./minishell", splited[i], 11) == 0 && ft_strlen(splited[i]) ==  11)
			minishell_cmd(&env);
		else if (ft_strncmp("unset", splited[i], 5) == 0 && ft_strlen(splited[i]) == 5)
			unset(&env, splited[i + 1]);
		else if (ft_strncmp("echo", splited[i], 4) == 0 && ft_strlen(splited[i]) == 4)
			my_echo(NULL, splited[i + 1],&env);
		else if (ft_strncmp("pwd", splited[i], 3) == 0 && ft_strlen(splited[i]) == 3)
			my_pwd(&env);
		i++;
	}
}


int main(int argc, char *argv[], char *env[])
{
    t_env	*env_new;
	
   char	*line;

    (void)argv;
	if (!env || !*env)
		return (1);
	if (argc > 2)
		return (0);
	

	env_cmd(env_new);
    while (1)
    {
      line = readline("minishell->");
	  if (!line && !*line)
	  {
		write (2, "exit\n", 6);
		break;
	  }
	  add_history(line);
	  check_line(line, env_new);
    }
    
	

}
