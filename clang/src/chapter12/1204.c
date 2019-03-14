#include <stdio.h>

#define MAX_LINE 512

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char buffer[MAX_LINE];
    
    printf("ファイルをコピーするプログラム\n");
    if (argc != 3) {
        printf("使用法： %s FILE1 FILE2\n", argv[0]);
        printf("FILE1 の内容を FILE2 にコピーします。\n");
        return(-1);
    }
    if ((fp1 = fopen(argv[1], "rb")) == NULL) {
        printf("ファイル %s が見つかりません。\n", argv[1]);
        return(-1);
    }
    if ((fp2 = fopen(argv[2], "wb")) == NULL) {
        printf("ファイル %s が作れません。\n", argv[2]);
        fclose(fp1);
        return(-1);
    }
    while (fgets(buffer, MAX_LINE, fp1) != NULL) {
        fputs(buffer, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return(0);
}
