#include <stdio.h>

void print_graph(int x);
int get_power(int x, int n);
int main(void);

void print_graph(int x)
{
    int i;

    for (i = 0; i < x; i++) {
        printf("*");
    }
    printf("\n");
}

int get_power(int x, int n)
{
    int i, y = 1;

    for (i = 0; i < n; i++) {
        y = y * x;
    }
    return(y);
}

int main(void)
{
    int i;

    for (i = -8; i <= 8; i++) {
        print_graph(get_power(i, 2));
    }
    return(0);
}
