/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:47:49 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/28 14:14:50 by zel-yama         ###   ########.fr       */
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

int check_longmax(const char  *str, int y)
{
	long	sum_long;
	long	sum;

	if (!str[y])
		return (0);
	sum_long = 1000;
	while (str[y] && ft_isdigit(str[y]) == 1)
	{
		sum += (int)str[y];
		y++;
	}
	if (sum > sum_long)
		return (1);	
	return (0);
}

long long	norm_atoi(const char *str, long long res, int *flag)
{
	int		i;
	int		sing;

	i = 0;
	sing = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sing *= -1;
		i++;
	}
	if (sing == 1 && check_longmax(str, i) == 1)
		return (*flag = -1,  2);
	while (str[i])
	{
		if (res < LONG_MIN)
			return (res * sing);
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	return (res * sing);
}
