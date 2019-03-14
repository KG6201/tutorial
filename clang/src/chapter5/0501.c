#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 128

int main(void);

int main(void)
{
    char buf[MAX_LINE];
    int n;

    printf("あなたの好物はどれですか？\n");
    printf("（１）春巻き\n");
    printf("（２）シューマイ\n");
    printf("（３）どちらでもない\n");
    fgets(buf, sizeof(buf), stdin);
    n = atoi(buf);
    switch (n) {
    case 1:
        printf("春巻きです。\n");
        break;

    case 2:
        printf("シューマイです。\n");
        break;

    default:
        printf("どちらでもありません。\n");
        break;
    }

    return(0);
}
