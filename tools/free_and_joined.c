/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_joined.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:20:30 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/02 12:14:54 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*free_and_join(char *store, char *s, int i)
{
	char	*str;

	str = ft_strjoin(store, s);
	if (i == 1 && store)
	{
		free(store);
		store = NULL;
	}
	else if (i == 2 && s)
	{
		free(s);
		s = NULL;
	}	
	else if (i == 3)
	{
		free_vars(store, s, NULL, NULL);
	}
	return (str);
}
