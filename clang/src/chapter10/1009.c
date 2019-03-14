#include <stdio.h>

struct student {
    int id;            /* 出席番号 */
    char name[20];     /* 氏名 */
    int kokugo;        /* 国語の点数 */
    int suugaku;       /* 数学の点数 */
    int eigo;          /* 英語の点数 */
};

struct student data[4] = {
    {1, "結城浩",    65,  90, 100},
    {2, "阿部和馬",  82,  73,  63},
    {3, "伊藤光一",  74,  31,  41},
    {4, "佐藤太郎", 100,  95,  98},
};

int main(void);
void print_total(struct student s);

int main(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        print_total(       );
    }
    return(0);
}

void print_total(struct student s)
{
    printf("%d %s の合計点は", s.id, &s.name[0]);
    printf(" %d 点です。\n",                              );
}

