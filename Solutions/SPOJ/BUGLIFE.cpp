#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<pii> vii;
typedef long long ll;
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

typedef vector<int> vi;
vector<vi> g;
vi color;

bool dfs(int u)
{
    for(int v: g[u])
    {
        if(color[v] == -1)      //Not assigned
        {
            color[v] = 1-color[u];
            if(!dfs(v)) return false;
        }

        if(color[v] == color[u])    return false;
    }

    return true;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int T;  cin >> T;
    for(int t = 1; t <= T; t++)
    {
        int n,m;    cin >> n >> m;
        g = vector<vi> (n+9);
        color = vi(n+9, -1);

        for(int i = 0; i < m; i++)
        {
            int u,v;    cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        bool can = true;
        for(int i = 1; i <= n; i++)
        {
            if(color[i] == -1)      //Not visited. New graph component.
            {
                color[i] = 0;
                can &= dfs(i);      //We use & operator because all components have to be 2-colorable (bipartite)
            }
        }

        cout << "Scenario #" << t << ":" << endl;
        if(can) cout << "No suspicious bugs found!" << endl;
        else    cout << "Suspicious bugs found!" << endl;
    }

    return 0;
}

