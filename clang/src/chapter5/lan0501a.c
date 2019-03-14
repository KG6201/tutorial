#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 256

int main(void);

int main(void)
{
    char buffer[MAXLINE];

    printf("曜日を 0 〜 6 の範囲で入力してください。\n");
    fgets(buffer, sizeof(buffer), stdin);
    switch (atoi(buffer)) {
    case 0:
        printf("日曜日\n");
        break;
        
    case 1:
        printf("月曜日\n");
        break;
        
    case 2:
        printf("火曜日\n");
        break;
        
    case 3:
        printf("水曜日\n");
        break;
        
    case 4:
        printf("木曜日\n");
        break;
        
    case 5:
        printf("金曜日\n");
        break;
        
    case 6:
        printf("土曜日\n");
        break;
        
    default:
        printf("0 〜 6 の範囲で入力してください\n");
        break;
    }
    return(0);
}
