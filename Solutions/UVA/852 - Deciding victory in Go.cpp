
//All the C++ libraries.
//#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <set>
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
#define clr(x, val)	memset((x), (val), sizeof(x))	//Not tested.
#define endl '\n'

char a[9][9];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int n = 9;

    int t;  cin >> t;
    while(t--)
    {
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];

        int xs = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 'X')    xs ++;
            if(a[i][j] == '.')
            {
                xs ++;      //Treat it as if it was in the territory of x

                //Check that it is really in the territory of x
                stack<pii> s;
                set<pii> visited;
                s.push({j, i});
                while(!s.empty())
                {
                    int x = s.top().first, y = s.top().second;
                    s.pop();

                    if(visited.find({x, y}) != visited.end())   continue;
                    if(x < 0 || x >= n || y < 0 || y >= n)  continue;
                    if(a[y][x] == 'X')    continue;
                    if(a[y][x] == 'O')    //The point turned out to be not in the territory of x
                    {
                        xs --;
                        break;
                    }

                    visited.insert({x, y});

                    s.push({x+1, y});
                    s.push({x-1, y});
                    s.push({x, y+1});
                    s.push({x, y-1});
                }
            }
        }

        //Do the same for O.
        int os = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 'O')    os ++;
            if(a[i][j] == '.')
            {
                stack<pii> s;
                set<pii> visited;
                s.push({j, i});
                while(!s.empty())
                {
                    int x = s.top().first, y = s.top().second;
                    s.pop();

                    if(visited.find({x, y}) != visited.end())   continue;
                    if(x < 0 || x >= n || y < 0 || y >= n)  continue;
                    if(a[y][x] == 'O')    continue;
                    if(a[y][x] == 'X')
                    {
                        os --;
                        break;
                    }

                    visited.insert({x, y});

                    s.push({x+1, y});
                    s.push({x-1, y});
                    s.push({x, y+1});
                    s.push({x, y-1});
                }
                os ++;
            }
        }

        printf("Black %d White %d\n", xs, os);
    }

    return 0;
}

