/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:04:51 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/29 10:52:47 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

t_env	*get_env(int argc, char *argv[], char *env[])
{
	t_env	*env_new;
	char	*pwd;

	(void)argc;
	(void)argv;
	if (!env || !*env)
		env_new = hard_code_env();
	else
		env_new = creat_env(env);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		perror("minishell: getcwd");
	pwd = free_and_join("=", pwd, 2);
	ft_lstadd_front(&env_new, node(ft_strjoin("DATA", pwd), 1));
	return (env_new);
}
