#include <stdio.h>

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int i;

    printf("argc の値は %d です。\n", argc);
    for (i = 0; i < argc; i++) {
        printf("argv[%d] の値は \"%s\" です。\n", i, argv[i]);
    }
    return(0);
}
