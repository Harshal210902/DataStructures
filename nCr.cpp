unsigned long long power(unsigned long long x, int y, int p)
{
    unsigned long long res = 1;

    x = x % p;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}
unsigned long long mul(unsigned long long x, unsigned long long y, int p)
{
    return x * 1ull * y % p;
}
unsigned long long divide(unsigned long long x, unsigned long long y, int p)
{
    return mul(x, modInverse(y, p), p);
}
unsigned long long nCr(unsigned long long n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    if (n - r < r)
        return nCr(n, n - r, p);

    unsigned long long res = 1;
    for (int i = r; i >= 1; i--)
        res = divide(mul(res, n - i + 1, p), i, p);
    return res;
}
