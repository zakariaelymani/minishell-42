/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnber.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:44:20 by zel-yama          #+#    #+#             */
/*   Updated: 2024/12/08 13:27:20 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
		ft_putnbr (nb, count);
	}
	else if (nb > 9)
	{
		ft_putnbr (nb / 10, count);
		ft_putchar ((nb % 10 + '0'), count);
	}
	else
	{
		ft_putchar ((nb + '0'), count);
	}
}
