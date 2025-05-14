#include "parsing_local.h"

int	main(void)
{
	t_token *toklist;
	char	*str = "cat >> file1 | ls << file2 | wc -l";

	toklist = ms_tokenizer(str);
	while (toklist->next)
	{
		ft_putendl_fd(toklist->content, 1);
		toklist = toklist->next;
	}
}
