
#include <stdio.h>
#include <string.h>
#include <strings.h>

size_t  varsize(char **str, char **env)
{
	size_t	namelen;
	char	*s;

	s = *str + 1;
	while (*env)
	{
		namelen = strchr(*env, '=') - *env;
		if (!strncmp(s, *env, namelen))
		{
			*str += namelen + 1;
			return (strlen(strchr(*env, '=') + 1));
		}
		env++;
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
			len++;
			while (*++str && *str != '\'')
				len++;
		}
		else if (*str && *str == '\"')
		{
			len++;
			str++;
			while (*str && *str != '\"')
			{
				if (*str == '$')
					len += varsize(&str, env);
				else
				{
					len++;
					str++;
				}
			}
		}
		else if (*str && *str == '$')
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
	char	*input = "$PATH";
	char	*env[] = {"PATH=/bin/ls", "a=test", NULL};
	size_t	i = expanded_size(input, env);
	printf("size : %ld\n", i);

}
