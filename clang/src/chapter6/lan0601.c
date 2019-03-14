#include <stdio.h>

int main(void);

int main(void)
{
    int i, j;

    for (i = 0; i < 9; i++) {
        printf("%d ", i);
        for (j = 0; j < i * i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return(0);
}
