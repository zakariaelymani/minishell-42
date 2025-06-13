/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:54:45 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/03 12:06:19 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

t_env	*hard_code_env(void)
{
	t_env	*env;
	char	*pwd;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	pwd = ft_strjoin("=", tmp);
	if (tmp)
		free(tmp);
	tmp = NULL;
	env = node(ft_strjoin("PWD", pwd), 1);
	env->next = node("PATH=/usr/local/sbin:/usr/local/bin: \
		/usr/sbin:/usr/bin:/sbin:/bin", 0);
	env->next->next = node("SHLVL=1", 0);
	env->next->next->next = node("_=/usr/bin/env", 0);
	return (env);
}
