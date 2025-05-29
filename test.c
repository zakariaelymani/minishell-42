
#include <stdio.h>
#include <string.h>
#include <strings.h>

size_t  varsize(char **str, char **env)
{
	size_t  result;

	while (*env)
	{
		if (!strncmp(*env, (*str)++, (strchr(*env, '=') - *env)))
		{
			while (**str && !strchr("$ \'\"", **str))
				(*str)++;
			result = strlen(strchr(*env, '=') + 1);
			return (result);
		}
	}
	return (0);
}

size_t	expanded_size(char *str, char **env)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str == '\'')
		{
			while (*str++ && *str != '\'')
				len++;
			len++;
		}
		else if (*str == '\"')
		{
			while (*str && *str != '\"')
			{
				if (*str == '$')
					len += varsize(&str, env);
				else
					len++;
			}
		}
		else if (*str == '$')
			len += varsize(&str, env);
		else
		{
			len++;
			str++;
		}
	}
	return (len);
}

int main()
{
	char	*input = "ls -la $PATH$PATH";
	char	*env[] = {"PATH=/bin/ls", NULL};
	size_t	i = expanded_size(input, env);
	printf("size : %ld\n", i);

}
