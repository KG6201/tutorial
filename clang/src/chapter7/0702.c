#include <stdio.h>

int main(void);

int main(void)
{
    int c;

    while ((c = getchar()) != '.') {
        printf("'%c'\n", c);
    }
    return(0);
}
