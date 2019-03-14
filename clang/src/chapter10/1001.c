#include <stdio.h>
#include <string.h>

struct student {
    int id;            /* 出席番号 */
    char name[20];     /* 氏名 */
    int kokugo;        /* 国語の点数 */
    int suugaku;       /* 数学の点数 */
    int eigo;          /* 英語の点数 */
};

int main(void);
void print_student(struct student s);

int main(void)
{
    struct student taro;
    struct student jiro;

    taro.id = 10;
    strcpy(&taro.name[0], "Yamada");
    taro.kokugo = 100;
    taro.suugaku = 85;
    taro.eigo = 60;

    jiro = taro;
    jiro.id = 11;
    strcpy(&jiro.name[0], "次郎");
    jiro.kokugo = 99;

    print_student(taro);
    print_student(jiro);
    return(0);
}

void print_student(struct student s)
{
    printf("出席番号:%d\n", s.id);
    printf("氏名:%s\n", &s.name[0]);
    printf("国語:%d\n", s.kokugo);
    printf("数学:%d\n", s.suugaku);
    printf("英語:%d\n", s.eigo);
    printf("合計:%d\n", s.kokugo + s.suugaku + s.eigo);
    printf("\n");
}
