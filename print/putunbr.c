/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:25:14 by zel-yama          #+#    #+#             */
/*   Updated: 2024/12/06 20:42:56 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunb(unsigned int unb, int *count)
{
	if (unb > 9)
	{
		ft_putunb(unb / 10, count);
		ft_putchar((unb % 10) + 48, count);
	}
	else
	{
		ft_putchar(unb + 48, count);
	}
}
