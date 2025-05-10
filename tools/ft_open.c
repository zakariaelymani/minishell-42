/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:43:52 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/10 16:53:01 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_open(char *file_name, t_redir type)
{
	int fd;

	fd = 0;
	if (type == INPUT)
		fd = open(file_name, O_RDONLY);
	else if (type == OUTPUT)
		fd = open (file_name,  O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == APPEND)
		fd = open (file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	
	return (fd);
}