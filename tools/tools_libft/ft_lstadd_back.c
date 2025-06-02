/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:05:46 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/24 16:04:41 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	if (!new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
