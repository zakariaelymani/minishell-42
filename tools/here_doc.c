/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:07:40 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/07 20:19:36 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	is_thathere(char *s, char c)
{
	int i;

	i = 0;
	if(!s)
		return (0);
	while(s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
void check_is_there()
{
    if (access("/tmp/here_doc", F_OK) == 0)
        unlink("/tmp/here_doc");
}

char *exapnd_var_form_env(char *line, t_env *env, int *i)
{
	int		var_len;
	char	*var_name;
	int 	copy;
	t_env	*tmp;

	if (!line || !env || !line[*i])
		return (NULL);
	(1) && (copy = 0, var_len = 0);
	var_len = *i;
	while (line[var_len] && (ft_isalnum(line[var_len]) == 1 || line[var_len] == '_' || line[var_len] ==  '?'))
		var_len++;
	var_len = var_len - *i;
	var_name = ft_substr(line, *i, var_len);
	*i += var_len;
	tmp = env;
	while(tmp)
	{
		if (compare("?", var_name) == 0)
			return(free(var_name), var_name = NULL, ft_itoa(tmp->exit_sta));
		if (compare(tmp->key, var_name) == 0)
			return (free(var_name), var_name = NULL, ft_strdup(tmp->value + 1));
		tmp = tmp->next;
	}
	return (free(var_name), var_name = NULL, NULL);
}

char *expantion(char *line, t_env *env)
{
	char 	*new_line;
	char 	*var_name;
	char 	*string;
	int		i;
	int		x;
	int		len_sub;
	
	(1) && (x = 0, var_name = NULL, new_line = NULL);
	while (1)
	{
		i = x;
		while (line[x] && line[x] != '$')
			x++;
		if (line[x] == '$' && line[x + 1] && (ft_isalnum(line[x + 1]) == 0 && line[x +  1] != '_' && line[x + 1] != '?'))
			x += 2;
		len_sub = x - i;
		string = ft_substr(line, i, len_sub);
		if (line[x] == '$' && line[x + 1])
			x++;
		new_line = free_and_join(new_line, string);
		new_line = free_and_join(new_line, exapnd_var_form_env(line, env, &x));
		if (!line[x])
			break ;
	}
	return (new_line);
}

int read_conten(char *limiter, int fd, t_env *env, int flag)
{
	char	buffer[2];
	char	*line;
	int		i;

	(1) && (line = NULL, i = 0);
	while (1)
    {
		line = readline(">");
		if (flag == -2)
			line = expantion(line, env);
      	if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break;
		else
			ft_putstr_fd(line, fd);
		(1) && (free(line), line = NULL);      
    }
	return (fd);
}

int     here_document(char *limiter, int flag, t_env **env)
{
    char    *line;
    int     i;
    int     fd;

    i = 0;
    check_is_there();
    fd = ft_open("/tmp/here_doc",  OUTPUT);
	line = NULL;
	fd = read_conten(limiter, fd, *env, flag);
	if (fd == -1)
		exit(1);
	close(fd);
	free(limiter);
	limiter = NULL;
	fd = ft_open("/tmp/here_doc", INPUT);
	unlink("/tmp/here_doc");
	return (fd);
}
