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
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;

#define loop(n)          for(int i = 0; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define iterate(v, i)    for(int i = 0; i < (v).size(); i++)

#define MP make_pair
#define PB push_back
#define all(a)   a.begin(),a.end()
#define endl '\n'

#define MAX 100000+9

int canReach[MAX];     ///canReach[x] = Number of nodes that can reach x
int moves[MAX];        ///moves[x] = Total(summation) number of moves required for all nodes that can reach x to reach it

/** Idea:
Each number x is a node in an implicit graph
The node x has directed edges to nodes 2*x and floor(x/2)

We want all numbers to become equal, so we will compute the cost of making all numbers in the array equal to x.
Try all values (1 <= x <= Maximum possible number in the array).
We can compute the number of moves required to make 'ai' equals x (for all values of x that Ai can reach) using BFS.
*/

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;  cin >> n;
    for(int i = 0; i < n; i++)
    {
        int ai;  cin >> ai;

        queue<pair<int, int>> q;        ///{moves, x}
        q.push({0, ai});                 ///'ai' can reach 'ai' with 0 moves.
        vector<bool> visited(MAX, false);

        ///BFS
        while(!q.empty())
        {
            int cost = q.front().first, x = q.front().second;
            q.pop();

            if(x >= MAX || visited[x])    continue;

            visited[x] = 1;
            canReach[x] ++;
            moves[x] += cost;

            q.push({cost+1, x/2});
            q.push({cost+1, x*2});
        }
    }

    int best = 1e9;
    for(int x = 1; x < MAX; x++)
    {
        if(canReach[x] == n)    best = min(best, moves[x]);
    }

    cout << best << endl;
    return 0;
}

