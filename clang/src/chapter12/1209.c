#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("ファイルの初めの%d行を表示するプログラム\n", LINES);
    for (i = 1; i < argc; i++) {
        print_file(       );
        printf("--pause--\n");
        getchar();
        printf("\n");
    }
    return(0);
}

void print_file(char *filename)
{
    if ((fp = fopen(        , "r")) == NULL) {
        printf("ファイル %s が見つかりません。\n", filename);
        return;
    }
    printf("ファイル %s : \n", filename);
    for (i = 0; i < LINES && fgets(buffer, MAX_LINE,   ) !=     ; i++) {
        printf("%s", buffer);
    }
}
