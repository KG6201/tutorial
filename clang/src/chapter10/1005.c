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
    int i;
    struct student data[3] = {
        {10, "Yamada",    100, 85, 60},
        {11, "Satou",      85, 95, 80},
        {12, "Takahashi",  72, 68, 78},
    };

    for (i = 0; i < 3; i++) {
        print_student(data[i]);
    }
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
