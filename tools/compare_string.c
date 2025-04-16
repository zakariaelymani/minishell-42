/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:46:09 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/15 16:46:51 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

//compare to string until find different 
int compare(const char *str, const char *str1)
{
    int i;
    
    i = 0;
    while (str[i] == str1[i])
        i++;
    return (str[i] - str1[i]);
}