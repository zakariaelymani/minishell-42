/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:57:22 by zel-yama          #+#    #+#             */
/*   Updated: 2024/11/05 10:44:13 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	lencouter(long n)
{
	long	len;
	long	num;

	num = n;
	len = 0;
	if (num < 0)
	{
		len++;
		num = -num;
		lencouter(num);
	}
	while (num > 9)
	{
		len++;
		num /= 10;
	}
	return (len + 1);
}

static char	*copyin(long n, char *s, long len)
{
	long	temp;

	temp = len;
	while (n > 0)
	{
		s[temp - 1] = (n % 10) + 48;
		n = n / 10;
		temp--;
	}
	s[len] = '\0';
	return (s);
}

static char	*zirocase(char *s)
{
	s = (char *)malloc(2 * sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	len;

	str = NULL;
	if (n == 0)
	{
		str = zirocase(str);
		return (str);
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = lencouter(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		copyin(n = -n, str + 1, len - 1);
	}
	else
		str = copyin(n, str, len);
	return (str);
}
