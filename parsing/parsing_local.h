/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_local.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:42:23 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/10 16:51:49 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_LOCAL_H
#define PARSING_LOCAL_H

#include "minishell.h"

typedef struct s_token{
	t_type	 type;
	char	*content;
	s_token	next;
}

#endif
