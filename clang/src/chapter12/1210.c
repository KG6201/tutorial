#include <stdio.h>

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    FILE *fp;
    int c;
    long offset;
    
    printf("16進ダンププログラム\n");
    if ((fp = fopen("rb")) == NULL) {
        printf("ファイル %s が見つかりません。\n", argv[1]);
        return(-1);
    }
    offset = 0L;
    while ((c = fgetc) != EOF) {
        printf("%02X", c % 256);
    }
    printf("\n");
    fclose(fp);
    return(0);
}
