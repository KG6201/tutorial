/*
 * 名前
 *    menu - メニュープログラム
 * 書式
 *    menu
 * 解説
 *    menu は、キーボードの入力に応じてそのコマンドを実行するものです。
 * 作者
 *    結城浩
 *    Copyright (C) 1994 by Hiroshi Yuki.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 条件コンパイル用のシンボル
 *
 * WIN_MENU を 1 にすると、Windwos 用のメニューになる。
 * WIN_MENU を 0 にすると、UNIX 用のメニューになる。
 */

#define WIN_MENU  0

/*
 * コマンド一覧
 */
#if WIN_MENU

#define CMD_DIR "dir"
#define CMD_DATE "date"
#define CMD_PWD "cd"

#else /* !WIN_MENU */

#define CMD_DIR "ls"
#define CMD_DATE "date"
#define CMD_PWD "pwd"

#endif /* !WIN_MENU */
    
#define MAX_LINE 128
/*
 * 関数のプロトタイプ宣言。
 */
int main(void);

/*
 * 関数 main() は、メイン関数である。
 */
int main(void)
{
    char buf[MAX_LINE];

    for (;;) {
        printf("メニュープログラム\n");
        printf("-----\n");
        printf("0 = 終了\n");
        printf("1 = ファイルの一覧表示(%s)\n", CMD_DIR);
        printf("2 = 今日の日付の表示(%s)\n", CMD_DATE);
        printf("3 = カレントディレクトリの表示(%s)\n", CMD_PWD);
        printf("-----\n");
        printf("番号でコマンドを入力してください：");
        fflush(stdout);
    
        fgets(buf, sizeof(buf), stdin);
        switch (atoi(buf)) {
        case 0:
            return(0);
            break;
    
        case 1:
            system(CMD_DIR);
            break;
    
        case 2:
            system(CMD_DATE);
            break;
    
        case 3:
            system(CMD_PWD);
            break;
    
        default:
            printf("0 〜 3 の範囲で入力してください。\n");
            break;
        }
    }
    /* ここにはこない */
    return(-1);
}
