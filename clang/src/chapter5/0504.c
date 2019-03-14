#include <stdio.h>

int main(void);

int main(void)
{
    int n = 1;
    
    switch (2 * n + 1) {
    case 0:
        printf("ゼロ\n");
        break;

    case 1:
        printf("イチ\n");
        break;

    case 2:
        printf("ニイ\n");
        break;

    case 3:
        printf("サン\n");
        break;

    default:
        printf("それ以外\n");
        break;
    }

    return(0);
}
