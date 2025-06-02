/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vars_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:39:08 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/02 12:03:05 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void free_vars(char *var1, char *var2, char *var3, char *var4)
{
	if (var1)
	{
		free(var1);
		var1  = NULL;
	}
	if (var2)
	{
		free(var2);
		var2 = NULL;
	}
	if (var3)
	{
		free(var3);
		var3 = NULL;
	}
	if (var4)
	{
		free(var4);
		var4 = NULL;
	}	
	if (var1)
		printf("this var one %p\n", var1);
	if (var2)
		printf("this var tow %p\n", var2);
	if (var3)
		printf("this var three %p\n", var3);
	if (var4)
		printf("this var four %p\n", var4);
}
