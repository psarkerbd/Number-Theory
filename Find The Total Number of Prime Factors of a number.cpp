#include<bits/stdc++.h>

#define limit 100100

using namespace std;

typedef long long LL;
typedef bitset<limit>bs;

int totalfactors[limit];

bs bit;

void find_total_factors()
{
    LL i,j;
    bit.set();
    bit[0] = bit[1] = 0;

    for(i=2; i<limit; i++)
    {
        if(bit[i])
        {
            totalfactors[i] = 1;

            for(j=i*2; j<limit; j+=i)
            {
                totalfactors[j] = 1 + totalfactors[j / i];

                bit[j] = 0;
            }
        }
    }
}

int main()
{
    find_total_factors();
    cout<<"Enter number to find total factors of that number: ";
    int number;
    while(cin >> number)
    {
        cout<<"Total Factors of " << number << " is = " << totalfactors[number] << "\n";

        cout<<"Enter number to find total factors of that number: ";
    }

    return 0;
}
