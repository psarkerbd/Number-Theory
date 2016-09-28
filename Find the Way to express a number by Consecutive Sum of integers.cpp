// Verdict :: Accepted
// Time :: 0.706

/// Header file begin
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <sstream>
#include <set>
#include <list>
#include <stack>
#include<utility>
#include <queue>
#include <algorithm>
/// End
//..........
/// Macro
#define sf scanf
#define pf printf
#define sfint(a,b) scanf("%d %d",&a,&b)
#define sfl(a,b) scanf("%ld %ld",&a,&b)
#define sfll(a,b) scanf("%lld %lld",&a,&b)
#define sfd(a,b) scanf("%lf %lf",&a,&b)
#define sff(a,b) scanf("%f %f",&a,&b)
#define lp1(i,n) for(i=0;i<n;i++)
#define lp2(i,n) for(i=1;i<=n;i++)
#define mem(c,v) memset(c,v,sizeof(c))
#define cp(a) cout<<" "<<a<<" "<<endl
#define nl puts("")
#define sq(x) ((x)*(x))
#define all(x) x.begin(),x.end()
#define reall(x) x.rbegin(),x.rend()
#define sz size()
#define gc getchar()
#define pb push_back
/// End.........

/// Size
#define mx7 20000100
#define mx6 1500000
#define mx5 100005
#define mx4 1000100
#define inf 1<<30                                           //infinity value
#define eps 1e-9
#define mx (65540)
#define mod 1000000007
#define pi acos(-1.0)

/// Macros for Graph

#define white 0
#define gray 1
#define black -1
#define nil -2

using namespace std;
//..................................................................................................................
typedef long long LL;
typedef long L;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned int ui;
typedef pair<int, int> pii;

map<int,int>mpii;
map<char,int>mpc;
map<string,int>mpsi;
map<bool,int>mpbi;

template<class T> T gcd(T a, T b ) {return b<=0?a:gcd(b,a%b);}
template<class T> T large(T a, T b ) {return a>b?a:b;}
template<class T> T small(T a, T b ) {return a<b?a:b;}
template<class T> T diffrnce(T a, T b) {return a-b<0?b-a:a-b;}

LL prime[(mx7>>6)+1],prm[(mx7>>1)+5],plen=0;

#define setbit(n) (prime[n>>6] |= (1<<((n>>1) & 31)))
#define checkbit(n) (prime[n>>6] & (1<<((n>>1) & 31)))

// Finding Primes by Seieve

void seieve(LL n)
{
    LL i,j,x=(long)sqrt(double(n));

    for(i=3;i<=x;i+=2)
    {
        if(!checkbit(i))
        {
            for(j=i*i;j<=n;j+=i+i)
            {
                setbit(j);
            }
        }
    }

    prm[plen++]=2;

    for(i=3;i<=n;i+=2)
    {
        if(!checkbit(i))
        {
            prm[plen++]=i;
        }
    }

    //lp1(i,plen)cout << prm[i] << " ";
}

LL way(LL n)
{
    LL m=1;

    for(int i=0;i<plen and sq(prm[i])<=n;i++)
    {
        if(!(n%prm[i]))
        {
            LL s=1;

            while(!(n%prm[i]))
            {
                //s++;
                if(n&1)s++; // Count all Odd number's factors
                n/=prm[i];
                if(n==0 or n==1) break;
            }

            if(n&1)
            {
                m*=s;
            }
                //m*=s;
        }
    }

    if(n>1)
    {
        m*=2;
    }

    //m--;

    return m;
}

int main()
{
    seieve(mx7);
    LL n;

    while(~sf("%lld",&n))
    {
        pf("%lld\n",way(n));
    }

    return 0;
}
