LL big_mod(LL n, LL p)
{
    if(p==0) return 1;

    if(!(p&1))
    {
        LL r = big_mod(n,p/2) % m;

        return ( (r%m) * (r%m) ) % m;
    }

    else
    {
        return ( ( n%m) * (big_mod(n,p-1) %m)) % m;
    }
}

int main()
{
    LL b,p;

    while(~sf("%lld %lld %lld",&b,&p,&m))
    {
        pf("%lld\n",big_mod(b,p));
    }

    return 0;
}
