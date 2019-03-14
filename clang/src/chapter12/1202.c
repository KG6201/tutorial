#include <stdio.h>

int main(void);

int main(void)
{
    char filename[FILENAME_MAX];
    FILE *fp1, *fp2;
    int c;
    
    printf("ファイルをコピーするプログラム\n");
    printf("コピー元のファイル名を入力してください。\n");
    gets(filename);
    if ((fp1 = fopen(filename, "rb")) == NULL) {
        printf("ファイル %s が見つかりません。\n", filename);
        return(-1);
    }
    printf("コピー先のファイル名を入力してください。\n");
    gets(filename);
    if ((fp2 = fopen(filename, "wb")) == NULL) {
        printf("ファイル %s が作れません。\n", filename);
        fclose(fp1);
        return(-1);
    }
    while ((c = fgetc(fp1)) != EOF) {
        fputc(c, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return(0);
}
