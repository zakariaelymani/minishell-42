/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:50:11 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/10 16:38:00 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../struct.h"
# include "../minishell.h"
# define BUFFER_SIZE 214

int				ft_isalpha(int c);
char			*ft_strdup(const char *s1);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
t_env			*ft_lstlast(t_env *lst);
int				ft_lstsize(t_env *lst);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
void			ft_lstadd_back(t_env **lst, t_env *new);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
void			free_while(char **array);
void			swap_string(char **str, char **str1);
t_env			*dup_list(t_env *env);
t_env			*node(char *value, int flag);
int				compare(const char *str, const char *str1);
int				find_env(char **env);
int				ft_isdigit(int c);
int				ft_isspace(int c);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*extract_key(char *value);
void			change_value_var(t_env **env, char *var_name, char *new_val);
char			*free_and_join(char *store, char *s, int i);
void			ft_putstr_fd(char *s, int fd);
int				here_document(char *limiter, int flag, t_env **env);
int				ft_open(char *file_name, t_type type);
char			**convert_strcut_array(t_env *env);
t_env			*hard_code_env(void);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				t_cmdsize(t_cmds *lst);
char			*find_path_to_cmd(t_env **env, char *cmd, int i);
t_cmds			*lstlast(t_cmds *lst);
void			*ft_memset(void *b, int c, size_t len);
void			add_var_just_not_exists(t_env **env, char *var_name,
					char *value);
void			clear_commands(t_cmds **cmds);
void			clear_env(t_env **env, int *last_status);
char			*return_value(t_env *env, char *var_name, int flag);
void			ft_lstadd_front(t_env **lst, t_env *new);
t_env			*get_env(int argc, char *argv[], char *env[]);
void			signals(int flag);
void			heredoc_handle(int sig);
void			safe_write(int fd, char *line, size_t len);
void			my_perror(char *who, char *input, char *description);
void			free_vars(char *var1, char *var2, char *var3, char *var4);
long long		norm_atoi(const char *str, long long res, int *flag);
size_t			ft_cpynbr(char *dest, int n);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strrchr(const char *s, int c);
int				handle_sigs_child(t_env **env, int status);
unsigned long	counterwords(const char *str, char c);
char			*get_next_line(int fd);
void			*ft_malloc(size_t size);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);

#endif
