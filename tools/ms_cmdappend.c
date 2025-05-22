/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmdappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:43:36 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/16 17:38:29 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    ms_cmdappend(t_cmds **lst, t_cmds *new)
{
        if (!lst || !new)
                return ;
        if (!*lst)
			*lst = new;
        else
			ms_cmdlast(*lst)->next = new;
}
