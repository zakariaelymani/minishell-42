/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_joined.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:20:30 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/16 22:30:23 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*free_and_join(char *store, char *s, int i)
{
	char	*str;

	str = ft_strjoin(store, s);
	if (i ==  1)
		free(store);
	else if (i  == 2)
		free(s);
	else if (i == 3)
	{
		free(s);
		free(store);
	}
	return (str);
}