#include "parsing_local.h"

char	*type_determiner(t_token *toklist)
{
	switch (toklist->type) {
		case WORD:
			return ("word");
		case OUTPUT:
			return ("output");
		case INPUT:
			return ("input");
		case HEREDOC:
			return ("heredoc");
		case APPEND:
			return ("append");
		case NONE:
			return ("none");
		case PIPE:
			return ("pipe");
	}
}

int	main(void)
{
	t_token *toklist;
	char	*str = "cat >> file1 | ls << file2 | wc -l";
	t_token	*head;

	toklist = ms_tokenizer(str);
	head = toklist;
	while (toklist)
	{
		printf("value:%s|\n", toklist->content);
		toklist = toklist->next;
	}
	ms_lstclear(&head, free);
}
