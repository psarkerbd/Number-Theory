#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int>pii;

pii EGCD(int a, int b)
{
    if(!b)
    {
        return pii(1, 0);
    }

    else
    {
        pii d = EGCD(b, a%b);

        return pii(d.second, d.first - (a / b) * d.second);
    }
}

int main()
{
    int a, b;

    while(cin >> a >> b)
    {
        pii ans = EGCD(a,b);

        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}
