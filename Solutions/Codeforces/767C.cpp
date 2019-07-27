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

#define maxn 1000009
int n, root;
int t[maxn];
int sum;                //The total sum of temperature
int sumUnder[maxn];     //sumUnder[u] = sum of temperature of the subtree under the node u (including u itself)
vector<vi> g(maxn);     //Directed graph (no edge from child no parent)

//The function returns the id of the node in the subtree of u that has sumUnder = sum/3 (or 0 if no such node exists)
int dfs(int u)
{
    sumUnder[u] = t[u];
    int found = 0;          //found: a node 'v' under 'u' that has sumUnder[v] = sum/3

    for(int v: g[u])
    {
        int candidate = dfs(v);
        sumUnder[u] += sumUnder[v];

        if(candidate)       //if candidate != 0 (candidate is a valid node that has sumUnder = sum/3)
        {
            if(!found)  found = candidate;

            else    //There are 2 nodes under u that have sumUnder = sum/3
            {
                cout << found << " " << candidate << endl;
                exit(0);
            }
        }
    }

    if(u != root && sumUnder[u] == (2*sum)/3 && found)
    {
        cout << found << " " << u << endl;
        exit(0);
    }

    if(sumUnder[u] == sum/3)    found = u;
    return found;
}


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;

    for(int u = 1; u <= n; u++)
    {
        int parent; cin >> parent;
        if(parent == 0)     root = u;
        else                g[parent].push_back(u);

        cin >> t[u];
        sum += t[u];
    }

    if(sum%3)   quit(-1);

    dfs(root);

    cout << -1 << endl;     //If dfs doesn't terminate the program
    return 0;
}

