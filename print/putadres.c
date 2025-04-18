/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putadres.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:31:09 by zel-yama          #+#    #+#             */
/*   Updated: 2024/12/06 20:43:18 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_adress(size_t nb, int *count)
{
	char	*s;

	s = "0123456789abcdef";
	if (nb >= 16)
	{
		put_adress(nb / 16, count);
		ft_putchar(s[nb % 16], count);
	}
	else
	{
		ft_putchar(s[nb % 16], count);
	}
}
