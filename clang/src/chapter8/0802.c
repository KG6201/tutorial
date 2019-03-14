#include <stdio.h>

float calc(float x);
int main(void);

float calc(float x)
{
    return(x * 0.7);
}

int main(void)
{
    float y;

    y = calc(10000.0);
    printf("値段 %.0f 円のとき", 10000.0);
    printf(" %.0f 円支払います。\n", y);
    return(0);
}
