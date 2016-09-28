#include<bits/stdc++.h>
using namespace std;

#define DIFF_SIZE 10010

int prm[DIFF_SIZE] , plen=0;

void sieve(int n)
{
    int i,j;

    bool mark[DIFF_SIZE];
    memset(mark, true, sizeof(mark));

    int qrt = sqrt(double(n)) + 1;

    for(int i=2; i*i<=n; i++)
    {
        if(mark[i])
        {
            for(j=2*i; j<=n; j+=i)
            {
                mark[j] = false;
            }
        }
    }

    for(i=2; i<=qrt; i++)
    {
        if(mark[i])
        {
            prm[plen++] = i;
        }
    }

    //for(i=0; i<plen; i++) cout << prm[i] << " ";
}

int main()
{
    int lowr, upr;

    while(cin >> lowr >> upr)
    {
        plen=0;

        sieve(upr);

        bool primenow[DIFF_SIZE];
        memset(primenow, true, sizeof(primenow));

        int i,j;

        for(i=0; i<plen; i++)
        {
            int  p = prm[i];
            int s = lowr / p;
            s*=p;

            for(j=s; j<=upr; j+=p)
            {
                if(j<lowr) continue;

                primenow[j-lowr] = false;
            }
        }

        for(i=0; i<plen; i++)
        {
            if(prm[i] >= lowr and prm[i] <= upr) cout << prm[i] << " ";
        }

        for(i=0; i<upr - lowr + 1; i++)
        {
            if(primenow[i]==true and (i+lowr) != 1)
            {
                cout << i+lowr << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}
