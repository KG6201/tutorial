#include <stdio.h>
#include <ctype.h>

int main(void);

int main(void)
{
    int c;
    long upper = 0L;
    long lower = 0L;
    long alpha = 0L;
    long space = 0L;

    while ((c = getchar()) != EOF) {
        if (isupper(c)) {
            upper++;
        }
        if (islower(c)) {
            lower++;
        }
        if (isalpha(c)) {
            alpha++;
        }
        if (isspace(c)) {
            space++;
        }
    }
    printf("uppercase = %ld\n", upper);
    printf("lowercase = %ld\n", lower);
    printf("alphabet = %ld\n", alpha);
    printf("space = %ld\n", space);
    return(0);
}
