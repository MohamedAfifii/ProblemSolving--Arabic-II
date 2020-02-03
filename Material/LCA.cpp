#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ll,ll> pll;

#define loop(n)          for(int i = 0; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)

#define len(s)   (int)s.length()
#define sz(v)    (int)v.size()
#define all(a)   a.begin(),a.end()
#define clr(x, val)	memset((x), (val), sizeof(x))
#define endl '\n'
#define quit(x)  return cout << (x) << endl,0;

const double pi  = 3.141592653589793238463;
typedef complex<double> point;
#define EPS 1e-8
#define EQ(x, y)	(abs((x)-(y)) <= EPS)
#define GT(x, y)	((x)-(y) > EPS)
#define LT(x, y)	((y)-(x) > EPS)
#define GTE(x, y)   (GT(x, y) || EQ(x, y))
#define LTE(x, y)   (LT(x, y) || EQ(x, y))
#define dot(u,v)                 	((conj(u)*(v)).real())
#define cross(u,v)                 	((conj(u)*(v)).imag())
#define colinear(a, b, c)           (EQ(cross(b-a, c-a),0))
/*****************************************************************************************/


vector<int> levels;

void TreeLevels(int root)
{
    stack<pii>  s;      ///<node, level>
    s.push({root, 0});

    while(!s.empty())
    {
        int u = s.top().first;
        int level = s.top().second;
        s.pop();

        levels[u] = level;

        for(int v: g[u])	if(p[u] != v)
        {
            s.push({v, level+1});
        }
    }
}


/**
Requirements:
- A vector 'p' representing the parent of each node.
- A vector<vector<int>> 'g' representing the children of each node as a directed graph.
- The nodes should be numbered from 1 to n
- n should be global

Side effect:
- twoPowerJthAnc[u][j]: The 2^j'th ancestor of u.

Today:
- Recover the k'th ancestor of u (for any k)
- Find the LCA(u,v)
O(NlogN)
*/

int n;
vector<vector<int>> g;
vector<int> p;
vector<vector<int>> twoPowerJthAnc; 

void buildLCA()
{
    for(int u = 1; u <= n; u++)
    {
        if(p[u] != u)   twoPowerJthAnc[u].push_back(p[u]);
        else            TreeLevels(u);
    }

    for(int j = 1; (1 << j) < n; j++)
    {
        for(int u = 1; u <= n; u++)
        {
            ///If u does not have a 2^(j-1)'th ancestor.
            if((int)twoPowerJthAnc[u].size() < j)   continue;
            int q = twoPowerJthAnc[u][j-1];

            ///If q does not have a 2^(j-1)'th ancestor.
            if((int)twoPowerJthAnc[q].size() < j)   continue;
            twoPowerJthAnc[u].push_back(twoPowerJthAnc[q][j-1]);
        }
    }
}


/**
Returns the k'th ancestor of q.
Returns -1 if the k'th ancestor doesn't exist.

O(logN)
*/
int KthAncestor(int u, int k)
{
    for(int j = 0; (1 << j) < n; j++)
    {
        if(k & (1<<j))
        {
            if(j >= (int)twoPowerJthAnc[u].size())    return -1;
            u = twoPowerJthAnc[u][j];
        }
    }

    return u;
}


/**
Returns the lowest common ancestor of u and v.
If u == v, the function returns u.

O(log N)
*/
int LCA(int u, int v)
{
    int l1 = levels[u];
    int l2 = levels[v];

    if(l1 > l2)     u = KthAncestor(u, l1-l2);
    if(l2 > l1)     v = KthAncestor(v, l2-l1);

    while(1)
    {
        if(u == v)  return u;

        int j = twoPowerJthAnc[u].size()-1;
        while(twoPowerJthAnc[u][j] == twoPowerJthAnc[v][j] && j > 0)
            j --;

        u = twoPowerJthAnc[u][j];
        v = twoPowerJthAnc[v][j];
    }
}

// https://www.spoj.com/problems/LCA/
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);


    int T;  cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> n;
        g = vector<vector<int>>(n+9);
        p = vector<int>(n+9);
        twoPowerJthAnc = vector<vector<int>>(n+9);
        levels = vector<int>(n+9);

        for(int u = 1; u <= n; u++) p[u] = u;

        for(int u = 1; u <= n; u++)
        {
            int m;  cin >> m;
            while(m--)
            {
                int v;  cin >> v;
                p[v] = u;
                g[u].push_back(v);
            }
        }

        buildLCA();

        cout << "Case " << t << ":" << endl;
        int q;  cin >> q;
        while(q--)
        {
            int u, v;   cin >> u >> v;
            cout << LCA(u, v) << endl;
        }
    }

    return 0;
}

