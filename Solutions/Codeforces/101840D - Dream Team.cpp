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

#define maxn 100009

vector<vi> divisors(maxn);
int a[maxn];
int in[maxn], out[maxn];

/**Idea:
You need to find the "maximum" spanning tree.
The cost of each edge is the gcd of the two numbers on the two nodes connected by the edge.

The problem is: Number of edges is N^2.
>> Can't generate a vector of edges and sort Wit!
>> Can't use Kruskal's algorithm!

Solution is:
Use Prim's algorithm.
- Whenever you add a new node to the tree, consider its divisors:
If you find one node outside the tree that shares a divisor with the node that you've just inserted to the tree,
add the corresponding edge to the priority queue.
- As usual with Prim's algorithm, find the edge on the queue that has the maximum cost and use it to append a new node to the tree.
*/

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("dream.in", "r", stdin);

    //Generate divisors for all numbers
    for(int n = 1; n < maxn; n++)
    {
        ll d;
        for(d = 1; d*d < n; d++)     if(n%d == 0)
        {
            divisors[n].push_back(d);
            divisors[n].push_back(n/d);
        }

        if(d*d == n)    divisors[n].push_back(d);
    }

    int T;  cin >> T;
    for(int t = 1; t <= T; t++)
    {
        int n;  cin >> n;
        loop(n) cin >> a[i];

        clr(in, 0); clr(out, 0);

        set<int> s;
        vector<set<int>> has(maxn);

        ///Initially, nodes from 1 to n-1 are outside the spanning tree
        for(int i = 1; i < n; i++)
        {
            for(int d: divisors[a[i]])
            {
                has[d].insert(a[i]);    //has[d]: set of nodes outside the tree that are divisible by d
            }
        }

        ///Initially, only node 0 is inside the tree
        for(int d: divisors[a[0]])
        {
            if(!has[d].empty())     //If a node outside the tree has d as one if its divisor
            {
                //s: set of divisors that divide nodes both inside and outside the tree
                //These divisors act like edges between nodes inside and outside the tree
                s.insert(d);
            }
        }

        ll ans = 0;
        for(int i = 0; i < n-1; i++)        //Need n-1 edges to build the spanning tree
        {
            int largest = *s.rbegin();      //Find the edge with maximum cost
            ans += largest;

            //Get any node from outside the tree that is divisible by "largest"
            //This node will get appended to the spanning tree
            int u = *has[largest].begin();

            for(int d: divisors[u])
            {
                //u is now inside the tree, erase it from the list of nodes outside the tree that are divisible by d
                has[d].erase(u);

                //Are there still nodes outside the tree divisible by d? If yes, add d as an edge.
                if(!has[d].empty())    s.insert(d);

                //If u was the last node outside the tree divisible by d, erase the edge (if it exists) that uses d.
                else                   s.erase(d);
            }
        }

        cout << "Case " << t << ": " << ans << endl;
    }
    return 0;
}

