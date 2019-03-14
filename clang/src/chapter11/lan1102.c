#include <stdio.h>  /* この中に NULL が定義されている */

char *scan_char(char *p, char c)
{
    while (*p != '\0') {
        if (*p == c) {
            /* 見つかったのでその位置を返す。*/
            return(p);
        }
        p++;
    }
    return(NULL);
}
