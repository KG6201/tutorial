#include <stdio.h>

int main(void);

int main(void)
{
    float x, y;

    x = 10000.0;
    y = x * 0.7;
    printf("値段 %.0f 円のとき", x);
    printf(" %.0f 円支払います。\n", y);
    return(0);
}
