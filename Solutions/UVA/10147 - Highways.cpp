
//All the C++ libraries.
//#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<double, pii> pdii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;

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
/*****************************************************************************************/

#define NUMNODES 800

struct DSU
{
    int parent[NUMNODES];

    DSU()
    {
        for(int i = 0; i < NUMNODES; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int FindLeader(int i)
    {
        if(parent[i] == i)  return i;
        return parent[i] = FindLeader(parent[i]);
    }

    bool SameTeam(int i, int j)
    {
        int x = FindLeader(i);
        int y = FindLeader(j);

        return x == y;
    }


    void MergeTeams(int i, int j)
    {
            int x = FindLeader(i), y = FindLeader(j);
            parent[y] = x;
    }

};


int x[NUMNODES], y[NUMNODES];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    bool newLine = false;
    int t;  cin >> t;
    while(t--)
    {
        int n;  cin >> n;
        for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];

        DSU s;
        vector<pdii> edges;

        for(int i = 1; i <= n; i++) for(int j = i+1; j <= n; j++)
        {
            int deltaX = x[i]-x[j], deltaY = y[i]-y[j];
            double cost = sqrt(deltaX*deltaX + deltaY*deltaY);

            edges.push_back({cost, {i, j}});
        }
        sort(edges.begin(), edges.end());


        //The existing highways have cost = 0
        //Add them first  
        int m;  cin >> m;
        while(m--)
        {
            int i, j;   cin >> i >> j;
            s.MergeTeams(i, j);
        }

        if(newLine) cout << endl;

        int num = 0;
        for(auto edge: edges)
        {
            int i = edge.second.first, j = edge.second.second;

            if(!s.SameTeam(i, j))
            {
                s.MergeTeams(i, j);
                cout << i << " " << j << endl;
                num ++;
            }
        }

        if(!num)    cout << "No new highways need" << endl;
        newLine = true;
    }

    return 0;
}
