/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carbdgecollcter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:11:17 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/16 19:51:56 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_free(void *ptr, int flag)
{
	static void	*collecter[INT_MAX];
	static int	i;
	int			j;
	
	if (flag)
	{
		j = 0;
		while(collecter[j])
			free(collecter[j++]);
	}
	else
		collecter[i++] = ptr;
}

void *ft_malloc(size_t size)
{
	void *ptr;
	
	ptr = malloc(size);
	if (!ptr)
		exit(2);
	ft_free(ptr, 0);
	return (ptr);
}