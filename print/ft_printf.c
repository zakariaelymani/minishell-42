/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:38:02 by zel-yama          #+#    #+#             */
/*   Updated: 2024/12/10 11:21:01 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	helpr_function(char c, int *count, va_list ap)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), count);
	if (c == 's')
		ft_putstr(va_arg(ap, const char *), count);
	if (c == 'x')
		ft_puthex(va_arg(ap, unsigned int), count);
	if (c == 'X')
		ft_put_upercase(va_arg(ap, unsigned int), count);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), count);
	if (c == 'p')
	{
		ft_putstr("0x", count);
		put_adress(va_arg(ap, size_t), count);
	}
	if (c == 'u')
		ft_putunb(va_arg(ap, unsigned int), count);
	if (c == '%')
		ft_putchar('%', count);
}

static int	check_in(char c)
{
	char	*s;
	int		i;

	i = 0;
	s = "csxXpudi%";
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	(1) && (count = 0, i = 0);
	va_start(args, format);
	if (write(1, "", 0) < 0)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && check_in(format[i + 1]))
		{
			helpr_function(format[i + 1], &count, args);
			i++;
		}
		else if (format[i] != '%')
		{
			ft_putchar(format[i], &count);
		}
		i++;
	}
	va_end(args);
	return (count);
}
