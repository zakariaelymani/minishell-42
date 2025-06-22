/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:56:03 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/22 21:56:21 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i++])
			return (1);
	}
	return (0);
}

int	ft_countwords(char *str, char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i] && !(is_separator(str[i], charset)))
		{
			count++;
			i++;
		}
		while (str[i] && !(is_separator(str[i], charset)))
			i++;
	}
	return (count);
}
