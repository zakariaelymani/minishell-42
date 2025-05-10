/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtoken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:22:11 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/10 16:46:08 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_token	*ft_newtok(void *name, t_type type)
{
	t_token	*result;

	result = (t_token *)malloc(sizeof(t_token));
	if (!result)
		return (NULL);
	result->type = type;
	result->content = content;
	result->next = NULL;
	return (result);
}
