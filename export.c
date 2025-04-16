/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:14:11 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/16 13:21:23 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void print_export(t_env *tmp)
{
	while (tmp)
	{
		if (!tmp->value || !*tmp->value)
			printf("declare -x %s\n", tmp->key);
		else
			printf("declare -x %s%s\n", tmp->key, tmp->value);
		tmp = tmp->next;	
	}
}

//print env sorted no 
void export_without(t_env *env)
{
	t_env	*dup_env;
	t_env	*tmp_env;
	t_env	*tmp;
	int 	size;

	dup_env = dup_list(env);
	size = ft_lstsize(env);
	tmp = dup_env;
	while (size-- > 0 && tmp_env)
	{
		tmp_env = dup_env;
		while (tmp_env->next)
		{
			if (compare(tmp_env->key, tmp_env->next->key) > 0)
			{
				swap_string(&tmp_env->key, &tmp_env->next->key);
				swap_string(&tmp_env->value, &tmp_env->next->value);
			}
			tmp_env = tmp_env->next;
		}
	}
	print_export(tmp);
}

//check name of var that will add to the env
int check_name(char *splited)
{
	int	i;

	i = 0;
	if (ft_isalpha(splited[i]) == 0 && splited[i] != '_')
	{
		write(2,"minishell tell this is invalid id \n", 36);
		return (1);
	}
	i++;
	while (splited[i] != '=' && splited[i] != '\0')
	{
		if (ft_isalnum(splited[i]) == 0)
		{
			write(2,"minishell tell this is invalid id >\n", 37);
			return (1);
		}
		i++;
	}
	return (0);
}

//check is var is the change value of that var 
int modify_var(char *input, t_env **env)
{
	t_env	*tmp;
	char	*new_value;

	tmp = (*env);
	while (tmp)
	{
		if (ft_strncmp(input, tmp->key, ft_strlen(tmp->key)) == 0
		&& ft_strlen(tmp->key) == ft_strlen(input))
		{
			new_value =	ft_strchr(input, '=');
			if (new_value && *new_value)
			{
				tmp->value = ft_strdup(new_value);
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	export(t_env **env, char *input)
{
	char	**splited;
	int		i;
	int		status;
	
    if (!input || !*input)
    { 
		export_without(*env);
		return ;
    }
	printf("%s\n", input);
	splited = ft_split(input, ' ');
	i = 0;
	status = 0;
	while (splited[i])
	{
		if (modify_var(splited[i], env) == 0)
		{
			write(2, "EHHEIF\n", 8);
			status = check_name(splited[i]); ///parse name of var key 
			if (status == 1)
				break ;
			else
				ft_lstadd_back(env, node(splited[i]));
		}
		i++;
	}
	//exit(status);
}
