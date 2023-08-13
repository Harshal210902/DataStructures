int countPrimeFactors(int num)
{
    int c = 0;
    while(num%2==0)
    {
        c=1;
        num/=2;
    }
    for(int i =3;i*i<=num;i+=2)
    {
        int d = 0;
        while(num%i==0)
        {
            d=1;
            num/=i;
        }
        c+=d;
    }
    if(num>1)c++;
    return c;
}
