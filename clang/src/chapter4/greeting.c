/*
 * 名前
 *  greeting - あいさつプログラム
 * 書式
 *  greeting         - 現在の時刻によりあいさつを表示する
 *  greeting HH:MM   - 現在が HH 時 MM 分だとしてあいさつを表示する
 * 例
 *  greeting         - 現在のあいさつ
 *  greeting 13:00   - 午後１時のあいさつ
 *  greeting 04:30   - 午前４時３０分のあいさつ
 * 解説
 *  プログラム greeting は、時刻に対応した適切な？あいさつを
 *  表示するプログラムである。
 * 作者
 *  結城浩
 *  Copyright (C) 1993 by Hiroshi Yuki.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 関数のプロトタイプ宣言
 */
int main(int argc, char *argv[]);
void print_greeting(int hour, int min);
void print_time(struct tm *tp);

/*
 * print_greeting() は時刻に応じたあいさつを表示する関数である。
 * 引数 hour は２４時制の「時」である。
 * 引数 min は「分」である。
 * 戻り値はない。
 */
void print_greeting(int hour, int min)
{
    /* 一般的なあいさつ */
    if ((22 <= hour && hour < 24) || (0 <= hour && hour < 4)) {/* 夜中 */
        printf("遅くまでご苦労さま。\n");
    }
    else if (hour < 7) {        /* 朝飯前 */
        printf("ずいぶんお早いですね。\n");
    }
    else if (hour < 12) {       /* 午前中 */
        printf("おはようございます。\n");
    }
    else if (hour < 15) {       /* 午後イチ */
        printf("こんにちわ。\n");
    }
    else if (hour < 18) {       /* 夕方 */
        printf("のんびりいきましょう。\n");
    }
    else if (hour < 22) {       /* 夜 */
        printf("こんばんわ。\n");
    }
    else {
        printf("%02d 時 %02d 分とは変な時刻ですね。\n", hour, min);
    }
    /* 特別なあいさつ */
    if (0 <= min && min < 10) {
        if (6 <= hour && hour < 9) {
            printf("朝ごはんは食べましたか？\n");
        }
        else if (hour == 12) {
            printf("昼ごはんは食べましたか？\n");
        }
        else if (18 <= hour && hour < 21) {
            printf("夕ごはんは食べましたか？\n");
        }
    }
}

/*
 * 関数 main() はメイン関数である。
 * 引数がない場合は現在の時刻によりあいさつを表示する。
 * 引数がある場合はその引数を "HH:MM" の形式の時刻だと判断して
 * あいさつを表示する。
 */
int main(int argc, char *argv[])
{
    time_t  now;
    struct tm   *tp;
    int hour, min;

    if (argc == 1) {        /* 引数がない場合 */
        now = time(NULL);   /* 現在時刻を取得する */
        tp = localtime(&now);   /* 時間構造体に変換する */
        printf("現在は ");
        print_time(tp);     /* 現在の日時を表示する */
        print_greeting(tp->tm_hour, tp->tm_min);
    }
    else {              /* それ以外の場合 */
        sscanf(argv[1], "%02d:%02d", &hour, &min);
        printf("指定された時刻は %02d 時 %02d 分です。\n", hour, min);
        print_greeting(hour, min);
    }
    return(0);
}

/*
 * weekday[] は 0 〜 6 を曜日に変換するための文字列の配列である。
 */
char *weekday[] = {"日","月","火","水","木","金","土"};

/*
 * print_time() は与えられた時間を表示する関数である。
 */
void print_time(struct tm *tp)
{
    printf("%d 年 %d 月 %d 日（%s） ",
        tp->tm_year + 1900,
        tp->tm_mon + 1,
        tp->tm_mday,
        weekday[tp->tm_wday]);
    printf("%02d 時 %02d 分 %d 秒です。\n",
        tp->tm_hour,
        tp->tm_min,
        tp->tm_sec);
}
