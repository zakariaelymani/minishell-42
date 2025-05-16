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
	char	*str = "tr -d \"    \" >> \'file1\' | ls << file2 | wc -l";
	t_cmds	*chain;

	toklist = ms_tokenizer(str);
	chain = cmd_parser(toklist);
	while (chain)
	{
		while (*(chain->cmds))
			printf("\"%s\" ", *(chain->cmds++));
		if (chain->redirection)
			printf("redir fname : %s\n", chain->redirection->file_name);
		chain = chain->next;
	}
}
