#include <stdlib.h>
#include <stdio.h>
//char *getenv(const char *name);

int main(int argc, char *argv[])
{
    char *var;

    var = getenv(argv[1]);
    printf("%s \n", var);
    return (0);
}