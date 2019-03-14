/*
 * 名前
 *  kuku - 九九練習プログラム
 * 書式
 *  kuku - 九九を練習する
 * 解説
 *  プログラム kuku は、九九の問題をランダムに２０個表示して
 *  その正解数と正解率を表示するプログラムである。
 * 作者
 *  結城浩
 *  Copyright (C) 1993 by Hiroshi Yuki.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Q    20  /* 表示する問題の個数 */
#define MAX_LINE 128 /* 入力行の最大長 */

int main(void);
void kuku(int questno);

int good_answers = 0;   /* 正答の個数 */

/*
 * 関数 main は九九の練習をする。
 * 問題をMAX_Q回繰り返す。
 * 最後に結果を表示する。
 */
int main(void)
{
    int i;
    float rate;

    /* 現在時刻を使って乱数の「種」を得る。*/
    srand((unsigned int)time(NULL));

    printf("これから九九の問題を %d 問出します。\n", MAX_Q);
    good_answers = 0;
    for (i = 0; i < MAX_Q; i++) {
        kuku(i);
    }
    rate = good_answers * 100.0 / MAX_Q;
    printf("問題は %d 問ありました。\n", MAX_Q);
    printf("%d 問は正しく答えられましたが、\n", good_answers);
    printf("%d 問は間違ってしまいました。\n", MAX_Q - good_answers);
    printf("正答率 %0.1f %%です。\n", rate);    
    printf("\n");
    printf("お疲れさま。\n");
    return(0);
}

/*
 * 関数 kuku は九九の問題を１問出し、答えを待つ。
 * 正答、誤答の別を表示する。
 */
void kuku(int questno)
{
    int x, y, result;
    char buffer[MAX_LINE];

    x = rand() % 9 + 1;
    y = rand() % 9 + 1;
    printf("［第 %d 問］　%d × %d ＝", questno + 1, x, y);
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    result = atoi(buffer);
    if (x * y == result) {
        printf("はい、正しいです。\n");
        good_answers++;
    }
    else {
        printf("残念、まちがいです。\n");
    }
    printf("\n");
}
