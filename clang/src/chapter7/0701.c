#include <stdio.h>

int main(void);

int main(void)
{
    int c;

    c = getchar();
    while (c != '.') {
        printf("'%c'\n", c);
        c = getchar();
    }
    return(0);
}
