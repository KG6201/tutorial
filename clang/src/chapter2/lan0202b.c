#include <stdio.h>

int daikei(int a, int b, int h);
int main(void);

int main(void)
{
    printf("%d\n", daikei(2, 3, 4));
    return(0);
}

/*
 * 関数 daikei は台形の面積を求める関数である。
 * 引数 a は上底の長さ、引数 b は下底の長さ、引数 h は高さである。
 * 台形の面積を求める公式は、
 * 　面積＝（上底＋下底）×高さ÷２
 * である。
 */
int daikei(int a, int b, int h)
{
    return((a + b) * h / 2);
}
