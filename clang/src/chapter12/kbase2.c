#include <stdio.h>
#include <stdlib.h>

char *usage[] = {
"名前",
"   kbase2 - 簡単成績処理",
"書式",
"   kbase2 input.doc [output.doc]",
"解説",
"   プログラム kbase2 は標準入力から生徒の名前と各教科の点数を受け取って、",
"   成績順に並べたり、平均点を求めたりします。",
"   出力ファイルを指定しないときには標準出力に出力します。",
"入力",
"   成績データは個人ごとに１行にまとめて書き、左から順に、",
"       <出席番号> <氏名> <点数1> <点数2> <点数3> <点数4> <点数5>",
"   の順で記入します。",
"入力例",
"       1 結城浩 65 90 100 80 73",
"       2 阿部和馬 82 73 63 21 44",
"       3 伊藤光一 74 31 41 59 38",
"出力",
"   ・出席番号順の名簿",
"   ・全教科の合計点による成績順位表、平均点・最高点・最低点",
"   ・合計点の平均",
"作者",
"   結城浩",
"   Copyright (C) 1993 by Hiroshi Yuki.",
NULL,
};

#define MAX_NAME 20 /* 氏名のサイズ */
#define MAX_LINE 512    /* １行のサイズ */
#define MAX_DATA 100    /* 処理できるデータの個数 */
#define MAX_TEN  5  /* 教科の数 */

/*
 * 構造体の宣言
 */

struct student {
    int id;         /* 出席番号 */
    char name[MAX_NAME];    /* 氏名 */
    int ten[MAX_TEN];   /* 教科ごとの点数 */
    double total;       /* 教科の合計点 */
};

/*
 * 以下は外部変数である。
 * 外部変数は関数の外で定義され、すべての関数で利用可能である。
 */

struct student data[MAX_DATA];  /* データを格納する配列 */
int max_student = 0;            /* 格納されているデータの数 */

/*
 * 関数のプロトタイプ宣言。
 */
int main(int argc, char *argv[]);
void fread_data(FILE *fp);
void sort_by_id(void);
void sort_by_total(void);
void fprint_data(FILE *fp);
void fprint_stat(FILE *fp);

/*
 * 関数 main() は、入力ファイルから学生のデータを読み込み、すべての
 * 処理を行うメイン関数である。
 */
int main(int argc, char *argv[])
{
    FILE *infp;
    FILE *outfp;
    
    /*
     * コマンドラインの解析とファイルのオープン
     */
    if (argc == 2) {
        if ((infp = fopen(argv[1], "r")) == NULL) {
            fprintf(stderr, "入力ファイル %s が見つかりません。\n", argv[1]);
            return(-1);
        }
        outfp = stdout;
    }
    else if (argc == 3) {
        if ((infp = fopen(argv[1], "r")) == NULL) {
            fprintf(stderr, "入力ファイル %s が見つかりません。\n", argv[1]);
            return(-1);
        }
        if ((outfp = fopen(argv[2], "w")) == NULL) {
            fprintf(stderr, "出力ファイル %s が作成できません。\n", argv[2]);
            return(-1);
        }
    }
    else {
        int i;
        
        for (i = 0; usage[i] != NULL; i++) {
            printf("%s\n", usage[i]);
        }
        return(0);
    }
    /*
     * 学生のデータを読み込み、学生の数を表示する。
     */
    fread_data(infp);
    fprintf(outfp, "\n");
    fprintf(outfp, "== 学生数 ==\n");
    fprintf(outfp, "%d 人\n", max_student);

    if (max_student <= 0) {
        fprintf(stderr, "データ数が少なすぎます。\n");
        return(-1);
    }

    /*
     * 出席番号順で並べ替え、名簿を表示する。
     */
    fprintf(outfp, "\n");
    fprintf(outfp, "== 出席番号順の名簿 ==\n");
    sort_by_id();
    fprint_data(outfp);

    /*
     * 合計点順で並べ替え、名簿を表示する。
     */
    fprintf(outfp, "\n");
    fprintf(outfp, "== 合計点による成績順位表 ==\n");
    sort_by_total();
    fprint_data(outfp);

    /*
     * 平均点・最高点・最低点を表示する。
     */
    fprintf(outfp, "\n");
    fprintf(outfp, "== 平均点・最高点・最低点 ==\n");
    fprint_stat(outfp);

    fclose(infp);
    fclose(outfp);
    return(0);
}

/*
 * 関数 fread_data() は、ファイルからデータを読み込む。
 * その際に、次のエラーが起こらないかどうかを調べ、エラーならプログラムを
 * 終了(exit)する。
 *  ・学生の数が多すぎる
 *  ・入力データの形式が誤っている
 * 変数 data[] と max_student を更新する。
 */

void fread_data(FILE *fp)
{
    int i = 0, j;
    char buffer[MAX_LINE];

    while (fgets(buffer, MAX_LINE, fp) != NULL) {
        if (i >= MAX_DATA) {
            fprintf(stderr, "学生数が多すぎます(最大 %d 人)\n", MAX_DATA);
            exit(-1);
        }
        /*
         * 関数 sscanf() を使ってデータを解析する。
         */
        if (sscanf(buffer, "%d %s %d %d %d %d %d\n", 
            &data[i].id,
            &data[i].name[0],
            &data[i].ten[0],
            &data[i].ten[1],
            &data[i].ten[2],
            &data[i].ten[3],
            &data[i].ten[4]) != 7) {
            fprintf(stderr, "%d 行目でデータの読み込みエラーになりました。\n", i + 1);
            fprintf(stderr, "%s", buffer);
            exit(-1);
        }
        /*
         * その学生の教科の合計点を計算しておく。
         */
        data[i].total = 0;
        for (j = 0; j < MAX_TEN; j++) {
            data[i].total += data[i].ten[j];
        }
        i++;
    }
    /*
     * 学生の数を更新する。
     */
    max_student = i;
}
/*
 * 関数 sort_by_id() は出席番号順で並べ替えを行う。
 */
void sort_by_id(void)
{
    int i, j;
    struct student tmp;

    for (i = 0; i < max_student - 1; i++) {
        for (j = i + 1; j < max_student; j++) {
            if (data[i].id > data[j].id) {
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}
/*
 * 関数 sort_by_total() は合計点数順で並べ替えを行う。
 */
void sort_by_total(void)
{
    int i, j;
    struct student tmp;

    for (i = 0; i < max_student - 1; i++) {
        for (j = i + 1; j < max_student; j++) {
            if (data[i].total < data[j].total) {
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}
/*
 * 関数 fprint_data() はデータを表示する。
 */
void fprint_data(FILE *fp)
{
    int i, j;

    for (i = 0; i < max_student; i++) {
        fprintf(fp, "%3d) %3d %-10s ", i + 1, data[i].id, data[i].name);
        for (j = 0; j < MAX_TEN; j++) {
            fprintf(fp, "%3d ", data[i].ten[j]);
        }
        /*
         * 合計点と平均点
         */
        fprintf(fp, " 合計点 %3.0f", data[i].total);
        fprintf(fp, " 平均点 %3.1f", data[i].total / MAX_TEN);
        fprintf(fp, "\n");
    }
}
/*
 * 関数 fprint_stat() は、教科ごとの平均点・最高点・最低点を計算し、
 * 表示する。また合計点の平均も表示する。
 */
void fprint_stat(FILE *fp)
{
    int max[MAX_TEN];   /* 教科ごとの最高点 */
    int min[MAX_TEN];   /* 教科ごとの最低点 */
    double ten[MAX_TEN];    /* 教科ごとの平均点 */
    double total;   /* 合計点の平均点 */
    int i, j;

    /* 0 番目の学生のデータで初期化 */
    for (j = 0; j < MAX_TEN; j++) {
        max[j] = data[0].ten[j];
        min[j] = data[0].ten[j];
        ten[j] = data[0].ten[j];
    }
    total = data[0].total;
    /*
     * 統計計算
     */
    for (i = 1; i < max_student; i++) {
        for (j = 0; j < MAX_TEN; j++) {
            if (max[j] < data[i].ten[j]) {
                max[j] = data[i].ten[j];
            }
            if (min[j] > data[i].ten[j]) {
                min[j] = data[i].ten[j];
            }
            ten[j] += data[i].ten[j];
        }
        total += data[i].total;
    }
    /*
     * 結果の出力
     */
    for (j = 0; j < MAX_TEN; j++) {
        fprintf(fp, "教科 %d : 最高点 %3d, 最低点 %3d, 平均点 %3.1f\n",
            j + 1, max[j], min[j], ten[j] / max_student);
    }
    fprintf(fp, "合計点の平均 %3.1f\n", total / max_student);
}
