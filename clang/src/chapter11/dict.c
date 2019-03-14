#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICT_DIC "dict.dic" /* 辞書ファイル名 */
#define MAX_LINE 128

char *usage[] = {
"名前",
"   dict - 辞書検索",
"書式",
"   dict 英単語",
"解説",
"   プログラム(dict)は、英単語と日本語訳の書かれたファイル（辞書ファイル）",
"   を検索し、入力された英単語の日本語訳を表示するプログラムです。",
"   辞書ファイルとして次のようなファイル(dict.dic)を用意します。",
"",
"   dictionary 辞書",
"   English 英語",
"   foreign 外国の",
"   home 家",
"   end 終了",
"",
"   そして、dict home と入力すると、",
"      home 家",
"   と画面に表示します。",
"作者",
"   結城浩",
"   Copyright (C) 1994 by Hiroshi Yuki.",
NULL,
};

/*
 * 単語を格納する構造体の宣言
 */
#define MAX_EWORD 20           /* 英単語の長さ */
#define MAX_JWORD 20           /* 和訳の長さ */
struct word {
    char eword[MAX_EWORD+1];     /* 英単語 */
    char jword[MAX_JWORD+1];     /* 和訳 */
};

/*
 * 以下は外部変数である。
 * 外部変数は関数の外で定義され、すべての関数で利用可能である。
 */
#define MAX_WORD 100           /* 単語の最大数 */
struct word data[MAX_WORD];    /* 単語を格納する配列 */
int max_word = 0;              /* 格納されている単語の数 */

/*
 * 関数のプロトタイプ宣言。
 */
int main(int argc, char *argv[]);
void fread_word(FILE *fp);

/*
 * 関数 main() は、メイン関数である。
 */
int main(int argc, char *argv[])
{
    int i;
    char eword[MAX_EWORD+1]; /* 検索する単語 */
    FILE *fp; /* 辞書ファイル */

    /*
     * コマンドラインの解析
     */
    if (argc != 2) {
        for (i = 0; usage[i] != NULL; i++) {
            printf("%s\n", usage[i]);
        }
        return(0);
    }

    /* 検索する単語を保存 */
    strcpy(eword, argv[1]);

    /* 辞書ファイルのオープン */
    fp = fopen(DICT_DIC, "r");
    if (fp == NULL) {
        fprintf(stderr, "辞書ファイル %s が見つかりません。\n", DICT_DIC);
        return(-1);
    }
    fread_word(fp);
    fclose(fp);

    /*
     * 単語を検索し、見つかったら表示する。
     */
    for (i = 0; i < max_word; i++) {
        if (strcmp(data[i].eword, eword) == 0) {
            printf("%s %s\n", data[i].eword, data[i].jword);
        }
    }
    return(0);
}

/*
 * 関数 fread_word() は、辞書ファイルからデータを読み込む。
 * その際に、次のエラーが起こらないかどうかを調べ、エラーならプログラムを
 * 終了(exit)する。
 *  ・単語の数が多すぎる
 *  ・入力データの形式が誤っている
 * 変数 data[] と max_word を更新する。
 */

void fread_word(FILE *fp)
{
    int i;
    char buffer[MAX_LINE];

    /* 辞書の読み込み */
    for (i = 0; fgets(buffer, MAX_LINE, fp) != NULL; i++) {
        if (i >= MAX_WORD) {
            fprintf(stderr, "単語数が多すぎます(最大 %d 人)\n", MAX_WORD);
            fclose(fp);
            exit(-1);
        }
        /*
         * 関数 sscanf() を使ってデータを解析する。
         */
        if (sscanf(buffer, "%s %s\n", data[i].eword, data[i].jword) != 2) {
            fprintf(stderr, "%d 行目でデータの読み込みエラーになりました。\n", i + 1);
            fclose(fp);
            exit(-1);
        }
    }
    max_word = i; /* 単語数 */
}
