
//All the C++ libraries.
//#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
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

#define MP make_pair
#define PB push_back
#define len(s)   (int)s.length()
#define sz(v)    (int)v.size()
#define all(a)   a.begin(),a.end()
#define clr(x, val)	memset((x), (val), sizeof(x))
#define endl '\n'
const double pi  = 3.141592653589793238463;
/*****************************************************************************************/

#define NUMNODES 10009

struct DSU
{
    int parent[NUMNODES];

    DSU()
    {
        for(int i = 0; i < NUMNODES; i++)   parent[i] = i;
    }

    int FindLeader(int i)
    {
        if(parent[i] == i)  return i;
        return parent[i] = FindLeader(parent[i]);
    }

    bool SameTeam(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);

        return leader1 == leader2;
    }

    void MergeTeams(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        parent[leader2] =  leader1;
    }
};

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n,m;    cin >> n >> m;
    vector<pair<int, pair<int,int>>> edges;     //{cost, {node1, node2}}

    for(int i = 0; i < m; i++)
    {
        int u, v, c;    cin >> u >> v >> c;
        edges.push_back({c, {u,v}});
    }

    sort(edges.begin(), edges.end());       //Will be sorted according to cost

    ll ans = 0;
    DSU dsu;

    for(auto edge:edges)
    {
        int c = edge.first;
        int u = edge.second.first, v = edge.second.second;

        if(!dsu.SameTeam(u, v)) dsu.MergeTeams(u, v), ans += c;
    }

    cout << ans << endl;
    return 0;
}
