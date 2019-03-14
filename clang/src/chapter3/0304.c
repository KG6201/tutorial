#include <stdio.h>

int main(void);

int main(void)
{
    printf("%f\n", 12.34);      /* 普通に表示 */
    printf("%6f\n", 12.34);     /* 少なくとも６桁で表示 */
    printf("%6.0f\n", 12.34);   /* 少なくとも６桁で、小数部は表示せず */
    printf("%6.1f\n", 12.34);   /* 少なくとも６桁で、小数第１位まで表示 */
    printf("%0.1f\n", 12.34);   /* 桁を気にせず小数第１位まで */
    return(0);
}
