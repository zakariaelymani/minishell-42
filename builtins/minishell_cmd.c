/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:14:37 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/08 09:30:31 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*join_equel(char *value)
{
	char	*joined;

	joined = ft_strjoin("=", value);
	free(value);
	return (joined);
}

int	check_value_of_shlvl(char *val)
{
	int	max_value;
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

void	minishell_cmd(t_env **env)
{
	t_env	*tmp;
	size_t	len;
	int		return_val;

	tmp = (*env);
	len = ft_strlen("SHLVL");
	while (tmp)
	{
		if (ft_strncmp("SHLVL", tmp->key, len) == 0
			&& len == ft_strlen(tmp->key))
		{
			return_val = check_value_of_shlvl(tmp->value + 1);
			return_val++;
			free(tmp->value);
			tmp->value = join_equel(ft_itoa(return_val));
			return ;
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(env, node("SHLVL=1", 0));
}

t_env	*creat_env(char **env)
{
	t_env	*new_env;
	int		lenv;
	t_env	*tmp;
	int		i;

	i = 1;
	lenv = find_env(env);
	new_env = node(env[0], 0);
	tmp = new_env;
	while (i < lenv)
	{
		new_env->next = node(env[i], 0);
		new_env = new_env->next;
		i++;
	}
	minishell_cmd(&tmp);
	add_var_just_not_exists(&tmp, "PATH",
		"=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
	change_value_var(&tmp, "SHELL", "=minishell");
	return (tmp);
}
