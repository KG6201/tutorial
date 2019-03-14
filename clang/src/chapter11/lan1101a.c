void swap_bigint(int *xp, int *yp)
{
    int tmp;
    
    if (*xp < *yp) {
        tmp = *xp;
        *xp = *yp;
        *yp = tmp;
    }
}
