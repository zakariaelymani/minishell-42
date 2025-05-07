/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:43:52 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/07 14:22:12 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_open(char *file_name, t_redir type)
{
	int fd;


	if (type == INPUT)
	{
		fd = open(file_name, O_RDONLY);
		//printf("input %s === fd %d\n", file_name, fd);
	}
	
	else if (type == OUTPUT)
	{
		fd = open (file_name,  O_CREAT | O_WRONLY | O_TRUNC, 0644);
		//printf("output %s === fd %d\n", file_name, fd);
	}
	else if (type == APPEND)
	{
		fd = open (file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
		//printf("appennd %s === fd %d\n", file_name, fd);
	}
		
		
	return (fd);
}