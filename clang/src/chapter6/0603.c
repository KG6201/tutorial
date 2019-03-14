#include <stdio.h>

int main(void);

int main(void)
{
    int i;

    for (i = 0; i < 10; i++) {
        printf("%d の二乗は %d で、", i, i * i);
        printf("三乗は %d です。\n", i * i * i);
    }
    return(0);
}
