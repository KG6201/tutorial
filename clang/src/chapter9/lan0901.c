#include <stdio.h>

#define MAX_DATA 10

int main(void);

int main(void)
{
    int i, max_data;
    int data[MAX_DATA] = { 31, 41, 59, 26, 53, 58, 97, 93, 23, 84 };

    max_data = data[0];
    for (i = 0; i < MAX_DATA; i++) {
        if (max_data < data[i]) {
            max_data = data[i];
        }
    }
    printf("最大値は %d\n", max_data);
    return(0);
}
