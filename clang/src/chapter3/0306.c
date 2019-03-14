#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 256

int main(void);

int main(void)
{
    char buffer[MAXLINE];
    int age;

    printf("あなたの名前を入力してください。\n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer)-1] = '\0';
    printf("%sさん、こんにちは。\n", buffer);

    printf("年齢を入力してください。\n");
    fgets(buffer, sizeof(buffer), stdin);
    age = atoi(buffer);
    printf("今 %d 歳とすると、10年後は %d 歳ですね。\n", age, age + 10);

    return(0);
}
