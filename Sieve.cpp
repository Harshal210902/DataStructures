void createSieve(int n)
{
    bool sieve[n+1];
    memset(sieve,true,sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;
    
    for(int i =0;i*i<=n;i++)
    {
        if(sieve[i])
        {
            for(int j = i*i;j<=n;j+=i)
            {
                sieve[j] = false;
            }
        }
    }

    for(int i =0;i<=n;i++)
    {
        cout<<i<<" "<<sieve[i]<<endl;
    }
}
