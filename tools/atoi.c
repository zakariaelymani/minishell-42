/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:47:49 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/17 15:44:35 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sing;

	i = 0;
	res = 0;
	sing = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sing *= -1;
		i++;
	}
	while (str[i])
	{
		if (res >= 999)
			return (res);
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	return (res * sing);
}

long	norm_atoi(const char *str)
{
	int		i;
	long	res;
	int		sing;

	i = 0;
	 res = 0;
	  sing = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sing *= -1;
		i++;
	}
	while (str[i])
	{
		if (res > INT_MAX)
			return (INT_MAX);
		if (res < INT_MIN)
			return (INT_MIN);
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	return (res * sing);
}
