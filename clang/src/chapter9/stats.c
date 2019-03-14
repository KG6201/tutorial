/*
 * 名前
 *  stats - 標準入力から数値データを入力して、その統計情報を出力する。
 * 書式
 *  stats < sample.s
 * 解説
 *  プログラム stats は標準入力から数値データを入力し、以下の計算を
 *  行う。
 *      ・データ数
 *      ・合計
 *      ・平均値
 *      ・最大値
 *      ・最小値
 *      ・中央値
 *  数値データは１行に１個だけ、行頭から書く。
 * 作者
 *  結城浩
 *  Copyright (C) 1993 by Hiroshi Yuki.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LINE 256    /* １行のサイズ */

#define MAX_DATA 500    /* 処理できるデータの個数 */

/*
 * 以下は外部変数である。
 * 外部変数は関数の外で定義され、すべての関数で利用可能である。
 */

double data[MAX_DATA];  /* データを格納する配列 */
int ind = 0;      /* 格納されているデータの数 */
double sum_data;    /* 合計 */
double ave_data;    /* 平均値 */
double max_data;    /* 最大値 */
double min_data;    /* 最小値 */
double mid_data;    /* 中央値 */

/*
 * 以下は関数宣言である。
 */

int main(void);
void input_data(void);
void calc_stats(void);
void output_data(void);

/*
 * 関数 main() は標準入力からデータを得、計算を行い、結果を表示する。
 */
int main(void)
{
    input_data();
    calc_stats();
    output_data();
    return(0);
}

/*
 * 関数 input_data() は標準入力からデータを入力し、外部変数 data[] に
 * 格納する。データ数の限界チェックを行い、越えるようならプログラムを
 * 終了する。データ数は外部変数 ind に格納する。
 */
void input_data(void)
{
    char buffer[MAX_LINE];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (ind >= MAX_DATA) {
            printf("処理できるデータ数を越えました。\n");
            printf("データ数は最大%d個です。\n", MAX_DATA);
            exit(-1);
        }
        else if (isdigit(buffer[0]) || buffer[0] == '.') {
            data[ind] = (double)atof(buffer);
            ind++;
        }
        else {
            /* 数字または . で始まらない行はそのまま表示する。*/
            printf("%s", buffer);
            
        }
    }
}

/*
 * 関数 calc_stats() は配列 data[] に入っているデータを元に
 * 各種統計情報を計算し、外部変数に格納する。
 */
void calc_stats(void)
{
    int i, j;
    double tmp;

    /* 合計の計算 */
    sum_data = 0.0;
    for (i = 0; i < ind; i++) {
        sum_data += data[i];
    }

    /* 平均値の計算 */
    ave_data = sum_data / ind;

    /* 最大値・最小値の計算 */
    if (ind > 0) {
        min_data = data[0];
        max_data = data[0];
    }
    for (i = 0; i < ind; i++) {
        if (min_data > data[i]) {
            min_data = data[i];
        }
        if (max_data < data[i]) {
            max_data = data[i];
        }
    }

    /* 中央値の計算 */
    /* いったんデータを小さい順序で並べ替える。*/
    for (i = 0; i < ind - 1; i++) {
        for (j = i + 1; j < ind; j++) {
            if (data[i] > data[j]) {
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
    mid_data = data[ind / 2];
}

/*
 * 関数 output_data() は、外部変数に格納された統計情報を表示する。
 */
void output_data(void)
{
    printf("データの個数 %d \n", ind);
    printf("合計 %g \n", sum_data);
    printf("平均値 %g \n", ave_data);
    printf("最大値 %g \n", max_data);
    printf("最小値 %g \n", min_data);
    printf("中央値 %g \n", mid_data);
}
