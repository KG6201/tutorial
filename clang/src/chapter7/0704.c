#include <stdio.h>
#include <ctype.h>

int main(void);

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (isupper(c)) {
            c = tolower(c);
        }
        putchar(c);
    }
    return(0);
}
