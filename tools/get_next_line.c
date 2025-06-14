/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:41:37 by zel-yama          #+#    #+#             */
/*   Updated: 2024/12/03 15:15:04 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*free_if(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (NULL);
}

char	*read_store(int fd, char *store)
{
	ssize_t	i;
	char	*buffer;

	i = 1;
	buffer = (char *)ft_malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(store, '\n') && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			if (buffer)
				free(buffer);
			return (free_if(store));
		}
		buffer[i] = '\0';
		store = free_and_join(store, buffer, 1);
	}
	free(buffer);
	if (store && !*store && i == 0)
		return (free_if(store));
	return (store);
}

char	*read_line(char *store)
{
	ssize_t	i;
	char	*str;

	i = 0;
	while (store[i] != '\n' && store[i])
		i++;
	if (store[i] == '\n')
		i++;
	str = (char *)ft_malloc(sizeof(char) * i + 1);
	if (!str)
		return (free_if(store));
	i = 0;
	while (store[i] != '\n' && store[i])
	{
		str[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*update_store(char *store)
{
	size_t	i;
	char	*temp;
	ssize_t	j;

	j = 0;
	i = 0;
	while (store[i] != '\n' && store[i])
		i++;
	if (store[i] == '\n')
		i++;
	temp = ft_malloc(ft_strlen(store) - i + 1);
	if (!temp)
		return (free_if(store));
	if (i >= ft_strlen(store))
		return (free(store), free(temp), NULL);
	while (store[i])
		temp[j++] = store[i++];
	temp[j] = '\0';
	free(store);
	store = NULL;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	store = read_store(fd, store);
	if (!store)
		return (NULL);
	line = read_line(store);
	if (!line)
		return (NULL);
	store = update_store(store);
	return (line);
}
