/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:22:31 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/28 11:22:55 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void safe_write(int fd, char *line, size_t len)
{
	if (write(fd, line, len) == -1)
	{
		perror("minshell: write");
		exit(1);
	}
}