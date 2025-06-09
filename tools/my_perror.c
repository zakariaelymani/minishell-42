/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:40:13 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/09 11:56:54 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	my_perror(char *who, char *input, char *description)
{
	safe_write(2, who, ft_strlen(who));
	safe_write(2, input, ft_strlen(input));
	safe_write(2, description, ft_strlen(description));
}
