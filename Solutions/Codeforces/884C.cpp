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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
typedef long double ld;
 
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
 
#define NUMNODES 100009
 
int parent[NUMNODES];
int TeamSize[NUMNODES];
 
struct DSU
{
    DSU()
    {
        for(int i = 0; i < NUMNODES; i++)
        {
            parent[i] = i;
            TeamSize[i] = 1;
        }
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
 
 
    ///Merge the teams of employee x and y.
    ///The better leader is the leader whose team size is larger.
    void MergeTeams(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
 
        if(leader1 == leader2)  return;
 
        if(TeamSize[leader1] > TeamSize[leader2])
        {
            parent[leader2] =  leader1;
            TeamSize[leader1] += TeamSize[leader2];
        }
 
        else
        {
            parent[leader1] =  leader2;
            TeamSize[leader2] += TeamSize[leader1];
        }
    }
 
    int GetSize(int x)
    {
        int leader = FindLeader(x);
        return TeamSize[leader];
    }
};
 
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    DSU s;
    int n;  cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int p;  cin >> p;
        s.MergeTeams(i, p);
    }
 
    vector<int> teams;
    for(int i = 1; i <= n; i++)
    {
        if(parent[i] == i)  teams.push_back(TeamSize[i]);
    }
 
    sort(all(teams));   reverse(all(teams));
 
    ll ans = 0;
    if(sz(teams) == 1)  ans = teams[0]*(ll)teams[0];
    else
    {
        ll mergedTeam = teams[0]+teams[1];
        ans = mergedTeam*mergedTeam;
 
        for(int i = 2; i < sz(teams); i++)  ans += teams[i]*(ll)teams[i];
    }
 
    cout << ans << endl;
    return 0;
}