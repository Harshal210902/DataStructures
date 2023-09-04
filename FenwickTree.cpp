int fenwick[N];
void update(int i, int add)
{
    while(i<N)
    {
        fenwick[i]+=add;
        i+=(i&(-1));
    }
}

int sum(int i)
{
    int s = 0;
    while(i>0)
    {
        s+=fenwick[i];
        i-=(i&(-i));
    }
    return s;
}
