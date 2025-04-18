/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:22:26 by zel-yama          #+#    #+#             */
/*   Updated: 2024/12/06 20:39:19 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int nb, int *count)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, count);
		ft_putchar("0123456789abcdef"[nb % 16], count);
	}
	else
	{
		ft_putchar("0123456789abcdef"[nb % 16], count);
	}
}
