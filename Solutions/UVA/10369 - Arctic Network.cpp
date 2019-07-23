
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

struct DSU
{
    int* parent;
    int numTeams;

    DSU(int n)
    {
        parent = new int[n];
        for(int i = 0; i < n; i++)  parent[i] = i;

        numTeams = n;
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
        if (!SameTeam(i, j))
        {
            int x = FindLeader(i), y = FindLeader(j);
            parent[y] = x;

            numTeams --;
        }
    }

};

#define MAXNODES 509

int x[MAXNODES], y[MAXNODES];

/** Idea:
Use minimum spanning tree until you get a forest that consists of a group of trees where the number of trees = number of satellite channels.

The communication within each tree will be through radio transceiver. While the communication between different trees willl be through satellite.
*/
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int t;  cin >> t;
    while(t--)
    {
        int sat, n;   cin >> sat >> n;
        loop(n)       cin >> x[i] >> y[i];

        DSU s(n);
        vector<pair<double, pii>> edges;

        for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++)
        {
            int deltaX = x[i]-x[j], deltaY = y[i]-y[j];
            double cost = sqrt(deltaX*deltaX + deltaY*deltaY);

            edges.push_back({cost, {i, j}});
        }
        sort(all(edges));

        double cost = 0;
        for(auto edge: edges)
        {
            if(s.numTeams <= sat)   break;

            cost = edge.first;
            int i = edge.second.first, j = edge.second.second;
            s.MergeTeams(i, j);
        }

        printf("%.2f\n", cost);
    }
    return 0;
}

