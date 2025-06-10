/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpynbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:24:01 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/06 15:24:05 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

static size_t	num_len(int n)
{
	size_t	result;
	long	num;

	num = (long)n;
	if (num == 0)
		return (1);
	result = 0;
	if (num < 0)
	{
		num *= -1;
		result++;
	}
	while (num > 0)
	{
		result++;
		num /= 10;
	}
	return (result);
}

size_t	ft_cpynbr(char *dest, int n)
{
	size_t	numlen;
	long	num;

	numlen = num_len(n);
	num = (long)n;
	if (num < 0)
	{
		*dest = '-';
		num *= -1;
	}
	*(dest + numlen) = '\0';
	while ((num / 10) > 0)
	{
		*(dest + --numlen) = (num % 10) + 48;
		num /= 10;
	}
	*(dest + --numlen) = (num % 10) + 48;
	return (numlen);
}
