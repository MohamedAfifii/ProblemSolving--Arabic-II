#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

#define loop(n)          for(int i = 0; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)

#define last(v)  v[sz(v)-1]
#define len(s)   (int)s.length()
#define sz(v)    (int)v.size()
#define all(a)   a.begin(),a.end()
#define clr(x, val)	memset((x), (val), sizeof(x))
#define endl '\n'
#define quit(x)  return cout << (x) << endl,0;

const double pi  = 3.141592653589793238463;
typedef complex<double> point;
#define EPS 1e-8
#define EQ(x, y)	(abs((x)-(y)) < EPS)
#define GT(x, y)	((x)-(y) > EPS)
#define LT(x, y)	((y)-(x) > EPS)
#define dot(u,v)                 	((conj(u)*(v)).real())
#define cross(u,v)                 	((conj(u)*(v)).imag())
#define colinear(a, b, c)           (EQ(cross(b-a, c-a),0))
/*****************************************************************************************/

#define maxn 100009

/** Idea:
Let m = n*k
First of all lets work with 0-based system
> Cities are numbered from 0 to m-1
> Restaurants are at cities 0, k, 2k, ..., (n-1)k.

Since the circle is symmetric, we can without any loss of generality assume that the first restaurant that he saw was at city 0.
> The start position was at either s1 = a or s1 = -a (-a is equivalent to m-a)

The second restaurant can be any of the n restaurants (0, k, 2k, ...)
> The second position (lets call it s2) can be at 0-b, 0+b, k-b, k+b, 2k-b, 2k+b, ...

Once you decide s2, you can compute l = s2 - s1
Once you know l, you can find the number of jumps as we saw in an earlier problem (https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/)
Then all what you have to do, is to loop over all possible values for s2 and find the minimum and maximum number of jumps.
*/

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n,k;    cin >> n >> k;
    ll m = n*k;
    ll a, b;   cin >> a >> b;
    vector<ll> ans;

    for(ll s1: {-a, a})
    {
        for(ll i = 0; i < n; i++)
        {
            ll pos = i*k;
            for(ll s2: {pos-b, pos+b})
            {
                ll l = s2-s1;

                //s2 can be smaller than s1 if the jump is large
                //Correct l to avoid negative jumps
                l = (l+m)%m;
                ans.push_back(m/__gcd(l,m));
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans[0] << " " << ans.back() << endl;
    return 0;
}

