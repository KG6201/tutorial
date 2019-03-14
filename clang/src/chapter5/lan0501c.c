#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 256

/* 番号と曜日の対応表 */
char *week[] = {
    "日曜日", "月曜日", "火曜日", "水曜日",
    "木曜日", "金曜日", "土曜日"
};

int main(void);

int main(void)
{
    char buffer[MAXLINE];
    int n;

    printf("曜日を 0 〜 6 の範囲で入力してください。\n");
    fgets(buffer, sizeof(buffer), stdin);
    n = atoi(buffer);
    if (0 <= n && n <= 6) {
        printf("%s\n", week[n]);
    }
    else {
        printf("0 〜 6 の範囲で入力してください\n");
    }
    return(0);
}
