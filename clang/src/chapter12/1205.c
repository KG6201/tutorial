#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 20 /* 氏名のサイズ */

int main(int argc, char *argv[]);
void print_usage(void);

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    int ten1, ten2, ten3;
    char name[MAX_NAME];
    
    if (argc != 3) {
        printf("使用法： %s INFILE OUTFILE\n", argv[0]);
        print_usage();
        return(-1);
    }
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        printf("ファイル %s が見つかりません。\n", argv[1]);
        return(-1);
    }
    if ((fp2 = fopen(argv[2], "w")) == NULL) {
        printf("ファイル %s が作れません。\n", argv[2]);
        fclose(fp1);
        return(-1);
    }
    while (fscanf(fp1, "%s %d %d %d\n", &name[0], &ten1, &ten2, &ten3) != EOF) {
        fprintf(fp2, "%-10s %3d %3d %3d  %3d\n", name, ten1, ten2, ten3,
            ten1 + ten2 + ten3);
    }
    fclose(fp1);
    fclose(fp2);
    return(0);
}

/*
 * print_usage() は使用法を表示する。
 */
void print_usage(void)
{
    printf("\n");
    printf("入力\n");
    printf("入力データは次のような形式で書きます。\n");
    printf("    結城浩 65 90 100\n");
    printf("    阿部和馬 82 73 63\n");
    printf("    伊藤光一 74 31 41\n");
    printf("    佐藤太郎 100 95 98\n");
    printf("    村松真治 55 48 79\n");
    printf("すなわち、各個人のデータは１行にまとめて書き、左から順に、\n");
    printf("    <氏名> <点数1> <点数2> <点数3>\n");
    printf("の順で記入します。\n");
    printf("\n");
    printf("出力\n");
    printf("出力データは次のような形式になります。\n");
    printf("    結城浩      65  90 100  255\n");
    printf("    阿部和馬    82  73  63  218\n");
    printf("    伊藤光一    74  31  41  146\n");
    printf("    佐藤太郎   100  95  98  293\n");
    printf("    村松真治    55  48  79  182\n");
    printf("すなわち、名前は左そろえ、数字は右そろえ、最後に合計点を出力します。\n");
}
