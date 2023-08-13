int xpowery(int x, int y)
{
    int ans = 1;
    if (x == 0)
        return 0LL;
    while (y)
    {
        if (y & 1)
            ans *= x;
        y >>= 1;
        x *= x;
    }
    return ans;
}
