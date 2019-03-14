#include <stdio.h>

void print_file(char *filename);
int main(int argc, char *argv[]);

#define LINES 20 /* 何行表示するか */
#define MAX_LINE 512

int main(int argc, char *argv[])
{
    int i;
    
    printf("ファイルの初めの%d行を表示するプログラム\n", LINES);
    if (argc < 2) {
        printf("使用法： %s FILE ... \n", argv[0]);
        return(-1);
    }
    for (i = 1; i < argc; i++) {
        print_file(argv[i]);
        printf("--pause--\n");
        getchar();
        printf("\n");
    }
    return(0);
}

/*
 * 指定されたファイルの初めの LINES 行を表示する。
 * LINES 行までいたらないファイルはファイルの終わりまで
 * 表示する。
 */

void print_file(char *filename)
{
    FILE *fp;
    int i;
    char buffer[MAX_LINE];

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("ファイル %s が見つかりません。\n", filename);
        return;
    }
    printf("ファイル %s : \n", filename);
    for (i = 0; i < LINES && fgets(buffer, MAX_LINE, fp) != NULL; i++) {
        printf("%s", buffer);
    }
    fclose(fp);
}
