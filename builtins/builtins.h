/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:23:46 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/20 11:33:11 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
#define BUILTINS_H

#include <sys/types.h>
#include "../struct.h"
#include "../tools/tools.h"

int 	env_cmd(t_env *env);
int		ft_exit(char **arguments);
int		export(t_env **env, char **splited);
t_env	*creat_env(char **env);
int     change_dir(char **new_path, t_env **env);
int     my_echo(char **string, t_env **env);
int		my_pwd(t_env **env);
int		unset(t_env **env, char **splited);
int		check_name(char *splited);
void	export_without(t_env *env);
int     check_name(char *splited);

#endif