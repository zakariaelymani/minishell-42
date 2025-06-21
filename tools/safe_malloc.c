/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:09:02 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/24 16:03:26 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	*ft_malloc(size_t size)
{
	void	*content;

	content = malloc(size);
	if (!content)
	{
		perror("malloc failed");
		exit(2);
	}
	return (content);
}
