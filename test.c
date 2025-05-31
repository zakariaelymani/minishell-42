
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
        size_t  i;
        size_t  len;

        i = 0;
        len = 0;
        while (src[i])
                i++;
        if (dstsize != 0)
        {
                while (src[len] != '\0' && len < (dstsize - 1))
                {
                        dst[len] = src[len];
                        len++;
                }
                dst[len] = '\0';
        }
        return (i);
}

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

int	env_cpy(char *dest, char **str, char **env)
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
			return (ft_strlcpy(dest, strchr(*env, '=') + 1, strlen(*env) - namelen));
		}
		env++;
	}
	return (0);
}

int	fill(char *dest, char *str, char **env)
{
	char	*head;

	head = str;
	while (*str)
	{
		if (*str == '\'')
		{
			*dest++ = *str++;
			while (*str && *str != '\'')
				*dest++ = *str++;
		}
		else if (*str && *str == '\"')
		{
			*dest++ = *str++;
			while (*str && *str != '\"')
			{
				if (*str == '$')
					dest += env_cpy(dest, &str, env);
				else
					*dest++ = *str++;
			}
		}
		else if (*str && *str == '$')
		{
			env_cpy(dest, &str, env);
			while (*dest)
			{
				if (*dest == ' ')
					*dest = '\x1F';
				dest++;
			}
		}
		else
			*dest++ = *str++;
	}
	return (0);
}

int main()
{
	char	*input = "$PATH";
	char	*env[] = {"PATH=ls -la", "a=", NULL};
	size_t	i = expanded_size(input, env);
	char	*result = malloc(i + 1);
	fill (result, input, env);
	printf("size : %ld\nresult: %s\n", i, result);
}
