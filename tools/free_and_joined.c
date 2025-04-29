/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_joined.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:20:30 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/28 16:17:55 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*free_and_join(char *store, char *s)
{
	char	*str;

	str = ft_strjoin(store, s);
	if (store && *store)
		free(store);
	store = NULL;
	return (str);
}