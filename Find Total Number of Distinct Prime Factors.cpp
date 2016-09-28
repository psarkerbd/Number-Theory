#include<bits/stdc++.h>

#define limit 100100

using namespace std;

typedef long long LL;
typedef bitset<limit>bs;

int distinctfactors[limit] = {0};

bs bit;

void distinct_Prime_factors()
{
    LL i,j;

    bit.set();
    bit[0] = bit[1] = 0;

    for(i=2; i<limit; i++)
    {
        if(bit[i])
        {
            for(j=i*2; j<limit; j+=i)
            {
                if(!(j % i))
                {
                    distinctfactors[j]+=1;
                }

                bit[j] = 0;
            }
        }
    }
    //for(i=2;i<10;i++)cout<<distinctfactors[i]<<" ";
}

int main()
{
    distinct_Prime_factors();
    cout << "Enter a number to find total distinct prime factor: ";
    int n;
    while(cin >> n)
    {
        cout << "Total Distinct Prime Factor = " << distinctfactors[n] << "\n";

        cout << "Enter a number to find total distinct prime factor: ";
    }

    return 0;
}
