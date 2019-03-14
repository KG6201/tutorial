#include <stdio.h>

#define MAX_DATA 10

int main(void);

int main(void)
{
    int i, j, tmp;
    int data[MAX_DATA] = { 31, 41, 59, 26, 53, 58, 97, 93, 23, 84 };

    printf("並べ替える前\n");
    for (i = 0; i < MAX_DATA; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }
    for (i = 0; i < MAX_DATA - 1; i++) {
        for (j = i + 1; j < MAX_DATA; j++) {
            if (data[i] > data[j]) {
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
    printf("並べ替えた後\n");
    for (i = 0; i < MAX_DATA; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }
    return(0);
}
