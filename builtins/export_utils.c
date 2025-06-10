/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:43:10 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/09 10:10:50 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	join_quote(t_env **tmp)
{
	char	*tmp_line;
	t_env	*env;

	tmp_line = NULL;
	env = (*tmp);
	while (env)
	{
		if (env->value)
		{
			tmp_line = env->value;
			if (env->value)
				env->value = free_and_join("\"", env->value + 1, 0);
			else
				env->value = free_and_join("\"", NULL, 0);
			free_vars(tmp_line, NULL, NULL, NULL);
			env->value = free_and_join(env->value, "\"", 1);
			env->value = free_and_join("=", env->value, 2);
		}
		env = env->next;
	}
}

void	print_export(t_env **env)
{
	t_env	*tmp;

	join_quote(env);
	tmp = *env;
	while (tmp)
	{
		if (!tmp->value || !*tmp->value)
			printf("declare -x %s\n", tmp->key);
		else
			printf("declare -x %s%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

void	export_without(t_env *env)
{
	t_env	*dup_env;
	t_env	*tmp_env;
	t_env	*tmp;
	int		size;

	dup_env = NULL;
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
	print_export(&tmp);
	clear_env(&tmp, &size);
}

int	check_name(char *splited)
{
	int	i;

	i = 0;
	if (ft_isalpha(splited[i]) == 0 && splited[i] != '_')
	{
		my_perror("minishell: export: ", splited,
			" is not a valid identifier\n");
		return (1);
	}
	i++;
	while (splited[i] != '=' && splited[i] != '\0')
	{
		if (ft_isalnum(splited[i]) == 0
			&& (splited[i] != '+' && splited[i + 1] != '='))
		{
			my_perror("minishell: export: ", splited,
				" is not a valid identifier\n");
			return (1);
		}
		i++;
	}
	return (0);
}
