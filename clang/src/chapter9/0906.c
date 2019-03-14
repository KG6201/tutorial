/* Shift_JIS を仮定 */
#include <stdio.h>

#define MAX_TEN 3

int main(void);

int main(void)
{
    int sum = 0, i;
    float heikin;
    int ten[MAX_TEN] = { 65, 90, 75 };
    char name[MAX_TEN][7] = { "国語", "数学", "英語" };

    for (i = 0; i < MAX_TEN; i++) {
        printf("%sは %d 点\n", &name[i][0], ten[i]);
        sum += ten[i];
    }
    heikin = (float)sum / MAX_TEN;
    printf("平均点は %.1f 点\n", heikin);
    return(0);
}
