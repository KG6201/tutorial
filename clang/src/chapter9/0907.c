/* Shift_JIS を仮定 */
#include <stdio.h>

#define MAX_TEN 3

int main(void);

int main(void)
{
    int sum = 0, i;
    float heikin;
    int ten[MAX_TEN] = { 65, 90, 75 };
    char namae[MAX_TEN][7] = {
    { '\xE5', '\x9B', '\xBD', '\xE8', '\xAA', '\x9E', '\0', }, /* "国語" */
    { '\xE6', '\x95', '\xB0', '\xE5', '\xAD', '\xA6', '\0', }, /* "数学" *///UTF8
    { '\xE8', '\x8B', '\xB1', '\xE8', '\xAA', '\x9E', '\0', }, /* "英語" */
    //{ '\x8D', '\x91', '\x8C', '\xEA', '\0', }, /* "国語" */
    //{ '\x90', '\x94', '\x8A', '\x77', '\0', }, /* "数学" *///SJIS
    //{ '\x89', '\x70', '\x8C', '\xEA', '\0', }, /* "英語" */
    };

    for (i = 0; i < MAX_TEN; i++) {
        printf("%sは %d 点\n", &namae[i][0], ten[i]);
        sum += ten[i];
    }
    heikin = (float)sum / MAX_TEN;
    printf("平均点は %.1f 点\n", heikin);
    return(0);
}
