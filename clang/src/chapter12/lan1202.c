#include <stdio.h>

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    FILE *fp;
    int c;
    long offset;
    
    printf("16進ダンププログラム\n");
    if (argc != 2) {
        printf("使用法： %s FILE\n", argv[0]);
        return(-1);
    }
    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("ファイル %s が見つかりません。\n", argv[1]);
        return(-1);
    }
    offset = 0L;
    while ((c = fgetc(fp)) != EOF) {
        if (offset % 16 == 0) {
            printf("\n%08X : ", offset);
        }
        printf("%02X", c % 256);
        if (offset % 16 == 7) {
            printf("-");
        }
        else {
            printf(" ");
        }
        offset++;
    }
    printf("\n");
    fclose(fp);
    return(0);
}
