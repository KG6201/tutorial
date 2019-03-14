/*
 * 名前
 *  janken - ジャンケンプログラム
 * 書式
 *  janken   - ジャンケンをする
 * 解説
 *  プログラム janken は、グーチョキパーを出して
 *  人間と対決し、結果を表示するプログラムである。
 * 作者
 *  結城浩
 *  Copyright (C) 1993 by Hiroshi Yuki.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GUU 0
#define CHO 1
#define PAA 2
#define HANDS   3

void learn(int lasthand, int curhand);
int guess(int curhand);
int winhand(int hand);
void printhand(int hand);
int judge(int hand1, int hand2);
void printbothhands(int chand, int mhand);
int main(void);

/*
 * 関数 learn() は以前の手 lasthand と 現在の手 curhand を記憶する。
 * 今は何も行わない。
 */
void learn(int lasthand, int curhand)
{
}

/*
 * 関数 guess() は以前の手から次の手を推測する。
 * 今はランダムに推測（？）している。
 */
int guess(int curhand)
{
    return(rand() % HANDS);
}

/*
 * 関数 winhand() は手 hand に勝つ手を返す。
 */
int winhand(int hand)
{
    if (hand == GUU) {
        return(PAA);
    }
    else if (hand == CHO) {
        return(GUU);
    }
    else if (hand == PAA) {
        return(CHO);
    }
    else {
        printf("関数 winhand(%d) に異常な値が渡されました。\n", hand);
        exit(-1);
    }
}

/*
 * 関数 printhand() は手 hand を文字列で表示する。
 */
void printhand(int hand)
{
    if (hand == GUU) {
        printf("グー");
    }
    else if (hand == CHO) {
        printf("チョキ");
    }
    else if (hand == PAA) {
        printf("パー");
    }
    else {
        printf("関数 printhand(%d) に異常な値が渡されました。\n", hand);
        exit(-1);
    }
}

/*
 * 関数 judge() は２つの手 hand1 と hand2 のどちらが勝ったかを判断する。
 *
 * hand1 が勝ったら 1 、hand2 が勝ったら 2 を返す。あいこなら 0 を返す。
 */
int judge(int hand1, int hand2)
{
    if (hand1 == hand2) {
        return(0);
    }
    else if (hand1 == winhand(hand2)) {
        return(1);
    }
    else if (winhand(hand1) == hand2) {
        return(2);
    }
    else {
        printf("関数 printhand(%d, %d) に異常な値が渡されました。\n",
            hand1, hand2);
        exit(-1);
    }
}

/*
 * 関数 printbothhands(chand, mhand) はコンピュータの手 chand と
 * 人間の手 mhand を表示する。
 */
void printbothhands(int chand, int mhand)
{
    printf("コンピュータは");
    printhand(chand);
    printf("、");
    printf("あなたは");
    printhand(mhand);
    printf("です。\n");
}

/*
 * 関数 main()
 */
int main(void)
{
    int wincom = 0; /* コンピュータの勝ち数 */
    int winman = 0; /* 人間の勝ち数 */
    int ndraw = 0;  /* 引き分けの数 */
    int hand = 0;   /* 人間の入力 */
    int lasthand = 0;   /* 人間の以前の入力 */
    int myhand = 0; /* コンピュータの入力 */
    int i, winner;
    char buffer[256];
    char c;

    printf("ジャンケンをしましょう。\n");
    printf("グーなら 1, チョキなら 2, パーなら 3 を入力してください。\n");
    printf("やめるときは 0 を入力してください。\n");
    for (i = 0; i < 1000; i++) {
        myhand = winhand(guess(hand));
        printf("ジャンケン…\n");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strlen(buffer) - 1] = '\0';
        c = buffer[0];    /* １文字目を取る */

        /* '0', '1', '2', '3' を -1, 0, 1, 2 に変換 */
        hand = c - '0' - 1;
        if (c == '0') {
            printf("やめたっと\n");
            break;
        }
        else if ('1' <= c && c <= '3') {
            printf("ポン！\n");
            winner = judge(myhand, hand);
            printbothhands(myhand, hand);
            if (winner == 1) {
                wincom++;
                printf("コンピュータの勝ち！\n");
            }
            else if (winner == 2) {
                winman++;
                printf("あなたの勝ち！\n");
            }
            else {
                ndraw++;
                printf("あいこ…\n");
            }
            printf("コンピュータ %d 勝,あなた %d 勝,引き分け %d\n",
            wincom, winman, ndraw);
            learn(lasthand, hand);
            lasthand = hand;
        }
        else {
            printf("？？？\n");
            printf("0, 1, 2, 3 のどれかのキーを押すのですよ。");
        }
        printf("\n");
    }
    if (wincom > winman * 2) {
        printf("コンピュータは賢いでしょう？\n");
    }
    else if (winman > wincom * 2) {
        printf("コンピュータ、完全敗北…\n");
    }
    else {
        printf("また遊んでね！\n");
    }
    return(0);
}
