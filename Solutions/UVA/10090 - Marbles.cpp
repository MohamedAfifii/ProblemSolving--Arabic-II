#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

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

ll floorDivision(ll x, ll y)
{
    return floor(x/ld(y));
}

ll ceilDivision(ll x, ll y)
{
    return ceil(x/ld(y));
}

/** Solution

Let a = n1, b = n2

* Find x, y such that ax + by = g
If n is not divisible by g, then there is no solution. Otherwise, correct x and y by multiplying them by the factor n/g.

* Consider the pair (x', y') from Bezout's identity
x' = x + kb/g
y' = y - kb/g

As you increase k: x' increases and y' decreases.
If the cost per marble c1/n1 is less than c2/n2, then we want to maximize x' and minimize y' to minimize the total cost. Otherwise we want to minimize x' and maximize y'.

* To maximize x', find the maximum k under the constraint y' >= 0
y - kb/g >= 0
k <= gy/a
kmax = floor(gy/a)

* To minimize y', find the minimum k under the constraint x' >= 0
x + kb/g >= 0
k >= -gx/b
kmin = ceil(-gx/b)

* Substitute k with kmin or kmax in Bezout's identity. Then check again that both x' and y' are non-negative as their might be no solution (can't achieve ax + by = n using positive x and y).

*/

int main()
{
    while(1)
    {
        ll n;   cin >> n;
        if(!n)  break;

        ll c1, n1;      cin >> c1 >> n1;
        ll c2, n2;      cin >> c2 >> n2;

        ll a = n1, b = n2;
        ll x, y;
        ll g = extended_euclid(a, b, x, y);

        if(n%g != 0)
        {
            cout << "failed" << endl;
            continue;
        }

        x *= n/g, y *= n/g;

        ll k;
        if(c1/ld(n1) < c2/ld(n2))   k = floorDivision(g*y, a);
        else                        k = ceilDivision(-g*x, b);

        x += (k*b)/g;
        y -= (k*a)/g;

        if(x < 0 || y < 0)      cout << "failed" << endl;
        else                    cout << x << " " << y << endl;
    }

    return 0;
}
