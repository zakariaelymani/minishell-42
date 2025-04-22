/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:50:11 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/21 11:38:25 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../struct.h"
#include "../minishell.h"

int     ft_isalpha(int c);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
t_env	*ft_lstlast(t_env *lst);
int     ft_lstsize(t_env *lst);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_lstadd_back(t_env **lst, t_env *new);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_isalnum(int c);
int     ft_isalpha(int c);
void	free_while(char **array);
void	swap_string(char **str, char **str1);
t_env	*dup_list(t_env *env);
t_env	*node(char *value);
int		compare(const char *str, const char *str1);
int		find_env(char **env);
int		ft_isdigit(int c);
int 	ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char    *extract_key(char *value);
long	norm_atoi(const char *str);
void    change_value_var(t_env **env, char *var_name, char *new_val);

#endif

 