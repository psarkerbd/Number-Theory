for only Prime Factors 

 

int num[mx7+9];

void nof()
{
    int i,j;

    for(i=4;i<=mx7;i+=2)
    {
        num[i] = 2;
    }

    for(i=3;i*i<=mx7;i+=2)
    {
        if(!num[i])
        {
            for(j=i*i;j<=mx7;j+=i)
            {
                num[j] = i;
            }
        }
    }

    for(i=2;i<=mx7;i++)
    {
        int n = num[i] ? num[i] : i;
        num[i] = 1 + num[i/n];
    }

    for(i=2;i<=21;i++)cp(num[i]);
}

int main()
{
    nof();
} 
