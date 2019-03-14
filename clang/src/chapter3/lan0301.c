#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 128

int main(void);

int main(void)
{
    char name1[MAX_LINE], name2[MAX_LINE];
    char buffer[MAX_LINE];
    float age1, age2;

    printf("２人の平均年齢を計算します。\n");

    printf("１人目の名前を入力してください。\n");
    fgets(name1, sizeof(name1), stdin);
    name1[strlen(name1)-1] = '\0';
    printf("%sさんの年齢を入力してください。\n", name1);
    fgets(buffer, sizeof(buffer), stdin);
    age1 = atoi(buffer);

    printf("２人目の名前を入力してください。\n");
    fgets(name2, sizeof(name2), stdin);
    name2[strlen(name2)-1] = '\0';
    printf("%sさんの年齢を入力してください。\n", name2);
    fgets(buffer, sizeof(buffer), stdin);
    age2 = atoi(buffer);

    printf("%sさんと%sさんの平均年齢は%0.1f歳です。\n",
        name1, name2, (age1 + age2) / 2);
    return(0);
}
