/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:19:30 by zel-yama          #+#    #+#             */
/*   Updated: 2024/12/08 13:30:23 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putstr(const char *s, int *count);
void	put_adress(size_t nb, int *count);
void	ft_puthex(unsigned int nb, int *count);
void	ft_putunb(unsigned int unb, int *count);
void	ft_put_upercase(unsigned int nb, int *count);
int		ft_printf(const char *format, ...);

#endif