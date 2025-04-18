/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:24:34 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/11 17:48:46 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "builtins.h"
#include <stdio.h> 
///mnt/homes/adafir/Desktop/
void change_dir(char *new_pwd)
{
    if (chdir(new_pwd) != 0)
        perror("cd ");

}

int main(int argc, char *argv[])
{
    change_dir(argv[1]);
    return (0);
}