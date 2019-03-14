#include <stdio.h>

int main(void);

int main(void)
{
    int n = -1;
    
    switch (n * n + 1) {
    case 1:
        if (n > 0) {
            printf("A\n");
        }
        else {
            printf("B\n");
        }
        break;

    case 2:
        if (n > 0) {
            printf("C\n");
        }
        else {
            printf("D\n");
        }
        break;

    default:
        printf("E\n");
        break;
    }

    return(0);
}
