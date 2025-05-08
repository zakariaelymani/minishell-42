#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "tools/tools.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "struct.h"
#include "builtins/builtins.h"
#include <sched.h>
#include <string.h>

int main()
{
    int i;

    int k;

    i = (int)&k;
    printf("%d\n", i);
    char *name =  ft_itoa(i);
    printf("%s\n", name);
}