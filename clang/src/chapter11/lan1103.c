#include <string.h>

void reverse_string(char *p)
{
    int len;
    char *q;
    int i;

    len = strlen(p);    /* 文字列の長さを得る。*/
    if (len > 0) {
        q = p + len - 1;    /* q は文字列の最後の文字を指す。*/
        for (i = 0; i < len / 2; i++) {
            char c = *p;
            *p = *q;
            *q = c;
            p++;
            q--;
        }
    }
}
