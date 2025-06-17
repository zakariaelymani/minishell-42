/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:07:40 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/09 15:12:35 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "parsing.h"

// char	*exapnd_var_form_env(char *line, t_env *env, int *i)
// {
// 	int		var_len;
// 	char	*var_name;
// 	t_env	*tmp;

// 	if (!line || !env || !line[*i])
// 		return (NULL);
// 	var_len = *i;
// 	while (line[var_len] && (ft_isalnum(line[var_len]) == 1
// 			|| line[var_len] == '_' || line[var_len] == '?' ))
// 		var_len++;
// 	var_len = var_len - *i;
// 	var_name = ft_substr(line, *i, var_len);
// 	*i += var_len;
// 	tmp = env;
// 	while (tmp)
// 	{
// 		if (compare("?", var_name) == 0)
// 			return (free(var_name), var_name = NULL, ft_itoa(tmp->exit_sta));
// 		if (compare(tmp->key, var_name) == 0 && tmp->status != -1)
// 			return (free(var_name), var_name = NULL, ft_strdup(tmp->value + 1));
// 		tmp = tmp->next;
// 	}
// 	return (free(var_name), var_name = NULL, NULL);
// }

// char	*expantion(char *line, t_env *env, int i, int x)
// {
// 	char	*new_line;
// 	char	*string;
// 	int		len_sub;

// 	(1) && (x = 0, new_line = NULL);
// 	while (1)
// 	{
// 		i = x;
// 		while (line[x] && line[x] != '$')
// 			x++;
// 		if (line[x] == '$' && line[x + 1] && (ft_isalnum(line[x + 1])
// 				== 0 && line[x + 1] != '_' && line[x + 1] != '?'))
// 			x += 1;
// 		len_sub = x - i;
// 		string = ft_substr(line, i, len_sub);
// 		if (line[x] == '$' && line[x + 1] && line[i + 1] != '$')
// 			x++;
// 		new_line = free_and_join(new_line, string, 3);
// 		new_line = free_and_join(new_line,
// 				exapnd_var_form_env(line, env, &x), 3);
// 		if (!line[x])
// 			break ;
// 	}
// 	return (free(line), new_line);
// }

int	read_conten(char *limiter, int fd, t_env *env, int flag)
{
	char	*line;
	int		i;

	(1) && (line = NULL, i = 0);
	while (1)
	{
		(signal(SIGINT, heredoc_handle), signal(SIGQUIT, SIG_IGN));
		safe_write(1, "> ", 3);
		line = get_next_line(STDIN_FILENO);
		if (!line && g_global_status == 3)
			return (g_global_status = 1, close(fd), -2);
		if (!line)
			return (write(2, "Delimiter not specified\n", 25), fd);
		if (flag == -2)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)))
				expand(&line, env);
		}
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			return (free(line), fd);
		else
			ft_putstr_fd(line, fd);
		(1) && (free(line), line = NULL);
	}
	return (fd);
}

char	*randomize_name(int fd)
{
	char	*name;
	char	*return_val;
	int		name_int;

	name_int = (long)&fd;
	name = ft_itoa(name_int);
	return_val = ft_strjoin("/tmp/", name);
	return (free(name), name = NULL, return_val);
}

int	here_document(char *limiter, int flag, t_env **env)
{
	int		fd;
	int		fd_input;
	char	*name;

	name = randomize_name(0);
	fd = ft_open(name, OUTPUT);
	fd_input = ft_open(name, INPUT);
	unlink(name);
	limiter = free_and_join(limiter, "\n", 0);
	fd = read_conten(limiter, fd, *env, flag);
	if (fd > -1)
		close(fd);
	free(limiter);
	limiter = NULL;
	if (fd == -2)
		(*env)->exit_sta = 130;
	if (fd == -1)
		(*env)->exit_sta = 1;
	if (fd == -2 || fd == -1)
		return (unlink(name), free(name), close(fd_input), -2);
	free(name);
	name = NULL;
	(*env)->exit_sta = 0;
	return (fd_input);
}
