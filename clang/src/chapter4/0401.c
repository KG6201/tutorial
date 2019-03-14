#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 128

int main(void);

int main(void)
{
    char buf[MAX_LINE];
    int n;

    printf("降水確率を入力してください。\n");
    fgets(buf, sizeof(buf), stdin);
    n = atoi(buf);
    printf("降水確率は %d %% です。\n", n);
    if (n >= 50) {
        printf("傘を忘れずにね。\n");
    }
    else {
        printf("傘はいりません。\n");
    }
    printf("いってらっしゃい。\n");

    return(0);
}
