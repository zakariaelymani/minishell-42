/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:14:37 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/01 18:52:51 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char *join_equel(char *value)
{
	char *joined;

	joined = ft_strjoin("=", value);
	free(value);
	return (joined);
}
//return value that be in shellvl if olthougth the problem if shell level is not valid we should turn to shlvl=1 or shelvl=0 if he is negative;  above this number or  is  include string 856124203 
//check si SHLVL VALUE IS VALID		
int	check_value_of_shlvl(char *val)
{
	int max_value;
	int	return_val;

	max_value = 999;
	if (!val || !*val)
		return (0);
	return_val = ft_atoi(val);
	if (return_val >= max_value)
	{
		write(2, "error in valid value to SHLVL\n", 31);
		return (0);    
	}
	else if (return_val < 0)
		return (-1);
	else
		return (return_val);
}

//when take the env we should take shell level and in increment it 
//by one we should store the value in static var and should exit form minishel if we reach that static var static var shell == static start var  so we do found it we  should add it ot env and we should put like this SHLVL=1 
void minishell_cmd(t_env **env)
{
	t_env	*tmp;
	size_t	len;
	int 	return_val;

	tmp = (*env);
	len = ft_strlen("SHLVL");
	while (tmp)
	{
		if (ft_strncmp("SHLVL", tmp->key, len) == 0 && len == ft_strlen(tmp->key))
		{
			return_val = check_value_of_shlvl(tmp->value + 1);
			return_val++;
			free(tmp->value);
			tmp->value = join_equel(ft_itoa(return_val));
			return ;
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(env, node("SHLVL=1"));
}

t_env *creat_env(char **env)
{
	t_env *new_env;
	int     lenv;
	t_env *tmp;
	int     i;
	
	i = 1;
	
	lenv = find_env(env);
	new_env = node(env[0]);
	tmp = new_env;
	while (i < lenv)
	{
		new_env->next = node(env[i]);
		new_env = new_env->next;
		i++;
	}
	minishell_cmd(&tmp);// this will change shlvl and modifie and 
	change_value_var(&tmp, "SHELL", "=minishell");
	return (tmp);
}