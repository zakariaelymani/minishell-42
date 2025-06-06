#include "parsing.h"

t_redir	*new_redir(t_type type)
{
	t_redir	*result;
	result = (t_redir *)malloc(sizeof(t_redir));
	if (!result)
		return (NULL);
	result->file_name = NULL;
	result->type = type;
	result->fd = -1;
	result->next = NULL;
	return (result);
}

t_redir *ms_redlast(t_redir *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void    ms_redappend(t_redir **lst, t_redir *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ms_redlast(*lst)->next = new;
}
