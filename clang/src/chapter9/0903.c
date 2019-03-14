#include <stdio.h>

int main(void);

int main(void)
{
    int ten[3], sum, i;
    float heikin;

    ten[0] = 65;
    ten[1] = 90;
    ten[2] = 75;
    sum = 0;
    for (i = 0; i < 3; i++) {
        sum = sum + ten[i];
    }
    heikin = sum / 3.0;
    printf("国語は %d 点\n", ten[0]);
    printf("数学は %d 点\n", ten[1]);
    printf("英語は %d 点\n", ten[2]);
    printf("平均点は %.1f 点\n", heikin);
    return(0);
}
