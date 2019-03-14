#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 256

int main(void);

int main(void)
{
    char buffer[MAXLINE];
    int hour;

    printf("時刻を入力してください。\n");
    fgets(buffer, sizeof(buffer), stdin);
    hour = atoi(buffer);
    if (hour < 0 || 24 <= hour) {
        printf("時刻の範囲を越えています\n");
    }
    else if (hour <= 11) {
        printf("おはようございます\n");
    }
    else if (hour == 12) {
        printf("お昼です\n");
    }
    else if (hour <= 18) {
        printf("こんにちわ\n");
    }
    else {
        printf("こんばんわ\n");
    }

    return(0);
}
