#include <stdio.h>
#include <stdlib.h>

int main(void);

int main(void)
{
    char c;

    printf("あなたの好物はどれですか？\n");
    printf("（ａ）春巻き\n");
    printf("（ｂ）シューマイ\n");
    printf("（ｃ）どちらでもない\n");
    c = getchar();
    switch (c) {
    case 'a':
        printf("春巻きです。\n");
        break;

    case 'b':
        printf("シューマイです。\n");
        break;

    default:
        printf("どちらでもありません。\n");
        break;
    }

    return(0);
}
