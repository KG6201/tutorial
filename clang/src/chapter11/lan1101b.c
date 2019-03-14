void swap_bigint(int *xp, int *yp)
{
    if (*xp < *yp) {
        int tmp = *xp;
        *xp = *yp;
        *yp = tmp;
    }
}
