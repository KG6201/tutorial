#include <stdio.h>

int main(void);

int main(void)
{
    char filename[FILENAME_MAX];
    FILE *fp;
    int c;
    
    printf("ファイルを表示するプログラム\n");
    printf("ファイル名を入力してください。\n");
    gets(filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ファイル %s が見つかりません。\n", filename);
        return(-1);
    }
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    fclose(fp);
    return(0);
}
