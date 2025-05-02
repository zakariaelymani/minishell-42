/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:43:10 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/29 12:22:53 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
	while (size-- > 0)
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
//INT_MAX
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
		if (ft_isalnum(splited[i]) == 0 && (splited[i] != '+' && splited[i + 1] != '='))
		{
			write(2,"minishell tell this is invalid id >\n", 37);
			return (1);
		}
		i++;
	}
	return (0);
}