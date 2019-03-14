#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 256

int main(void);

int main(void)
{
    char buffer[MAXLINE];
    int n;

    printf("曜日を 0 〜 6 の範囲で入力してください。\n");
    fgets(buffer, sizeof(buffer), stdin);
    n = atoi(buffer);
    if (n == 0) {
        printf("日曜日\n");
    }
    else if (n == 1) {
        printf("月曜日\n");
    }
    else if (n == 2) {
        printf("火曜日\n");
    }
    else if (n == 3) {
        printf("水曜日\n");
    }
    else if (n == 4) {
        printf("木曜日\n");
    }
    else if (n == 5) {
        printf("金曜日\n");
    }
    else if (n == 6) {
        printf("土曜日\n");
    }
    else {
        printf("0 〜 6 の範囲で入力してください\n");
    }
    return(0);
}
