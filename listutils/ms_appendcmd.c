/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_appendcmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:43:36 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/15 14:45:48 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_local.h"

void    ms_appendcmd(t_cmds **lst, t_cmds *new)
{
        if (!lst || !new)
                return ;
        if (!*lst)
			*lst = new;
        else
			ms_cmdlast(*lst)->next = new;
}
