#include "parsing_local.h"

int	main(void)
{
	t_token *toklist;
	char	*str = "cat >> file1 | ls << file2 | wc -l";
	t_token	*head;

	toklist = ms_tokenizer(str);
	head = toklist;
	while (toklist)
	{
		ft_putendl_fd(toklist->content, 1);
		toklist = toklist->next;
	}
	ms_lstclear(&head, free);
}
