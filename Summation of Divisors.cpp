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
#define sfint(a) scanf("%d",&a)
#define sfl(a,b) scanf("%ld %ld",&a,&b)
#define sfll(a,b) scanf("%lld %lld",&a,&b)
#define sfd(a,b) scanf("%lf %lf",&a,&b)
#define sff(a,b) scanf("%f %f",&a,&b)
#define lp1(i,n) for(i=0;i<n;i++)
#define lp2(i,n) for(i=1;i<=n;i++)
#define mem(c,v) memset(c,v,sizeof(c))
#define cp(a) cout<<" "<<a<<" "
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
/***************/

/// typedef

typedef long long LL;
typedef long L;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned int ui;
typedef pair<int, int> pii;
typedef vector<int>vi;
typedef vector<long long> vll;
typedef vector<long>vl;
typedef vector<char>vch;
typedef vector<string>vs;
typedef map<int,int>mpii;
typedef map<int,bool>mpbi;
typedef map<char,int>mpci;
typedef map<char,bool>mpbc;
typedef map<string,int>mpsi;
typedef map<long long,long long>mpll;

/// template

template<class T> T gcd(T a, T b ) {return b<=0?a:gcd(b,a%b);}
template<class T> T large(T a, T b ) {return a>b?a:b;}
template<class T> T small(T a, T b ) {return a<b?a:b;}
template<class T> T diffrnce(T a, T b) {return a-b<0?b-a:a-b;}


using namespace std;
//..................................................................................................................
template<class T> T setbit(T n, T pos){n=n|(1<<pos); return n;}
template<class T> T checkbit(T n, T pos){n=n&(1<<pos); return n;}

int prime[1],pr[100],plen=0;

void seieve(int n)
{
    int i,j,x=sqrt(n);

    prime[0]=setbit(prime[0],0);
    prime[0]=setbit(prime[0],1);

    for(i=4;i<=n;i+=2)prime[i>>5]=setbit(prime[i>>5],i&31);

    for(i=3;i<=x;i+=2)
    {
        if(!checkbit(prime[i>>5],i&31))
        {
            for(j=i*i;j<=n;j+=i)
            {
                prime[j>>5]=setbit(prime[j>>5],j&31);
            }
        }
    }

    for(i=2;i<=n;i++)
    {
        if(!checkbit(prime[i>>5],i&31))
        {
            pr[plen++]=i;
        }
    }
}

mpii mp;

void divisor(int n)
{
    int i,m=1,tmp,take=n;

    mp.clear();

    for(i=0;i<plen and sq(pr[i])<=n;i++)
    {
        if(!(n%pr[i]))
        {
            while(!(n%pr[i]))
            {
                mp[pr[i]]++;
                n/=pr[i];
                if(n==0 or n==1) break;
            }

            tmp=powl(pr[i],(mp[pr[i]] + 1));
            m*=((tmp-1)/(pr[i] - 1));
        }
    }

    if(n>1)
    {
        tmp=powl(n,2);
        m*=((tmp-1) / (n-1));
    }

    pf("Summation of the divisors of %d is %d :)\n",take,m);
    m=1;
}

int main()
{
    int n;
    seieve(100);

    cout << "Enter Number(up to 100) : ";

    while(sfint(n)==1)
    {
         divisor(n);

         cout << endl << "Enter Number(up to 100) : ";
    }

    return 0;
}

//================================================================================================================
/*

                                         Summation of Divisors
                                         =====================

Let the divisors of 60 = 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30 and 60; Total=12;

So, the total Summation of that divisors is = 1+2+3+4+5+6+10+12+15+20+30+60 = 168;

Formula::
==========

( r ^ ( n + 1 ) - 1 ) / ( r - 1 );

**** r = prime factorization of that number. n = power of the prime factorization.

So, for 60 = 2^2 * 3^1 * 5^1 ;

r=2,3,5;

n=2,1,1;

result = ( ( 2 ^ ( 2 + 1 ) ) - 1 ) / (2-1) * ( ( 3 ^ ( 1 + 1 ) ) - 1 ) / (3-1) * ( ( 5 ^ ( 1 + 1 ) ) - 1 ) / (5-1);

=> result = 7 * 4 * 6 = 168 ;

so, result = 168;

*** In which function that we get the summation of divisor is called Sigma function ;)
*/
