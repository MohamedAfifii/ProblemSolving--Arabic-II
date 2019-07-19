#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }

    ll g = extended_euclid(b, a%b, y, x);
    y -= (a/b)*x;
    return g;
}

/**
Let us change the symbols used in the problem to avoid conflict with the symbols that we are used to when dealing with Euclid algorithm:

You are given to integers c and d. Find x and y such that:
floor(c/d)*x + ceil(c/d)*y = c

Solution
1. Compute a = floor(c/d), b = ceil(c/d)
2. Find x and y such that ax + by = g
3. Correct x and y by multiplying by the factor c/g such that ax + by becomes = c
*/

int main()
{
    int t;  cin >> t;
    while(t--)
    {
        ll c, d;     cin >> c >> d;
        ll a = floor(c/float(d)), b = ceil(c/float(d));

        ll x, y;
        ll g = extended_euclid(a, b, x, y);
        x *= c/g;
        y *= c/g;

        cout << x << " " << y << endl;
    }

    return 0;
}

