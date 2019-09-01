#include <bits/stdc++.h>
using namespace std;

#define maxn 1000009
int n;
int a[maxn];
int dp[maxn][2];

int sol(int i, int stage)
{
    if(i == n || stage == 2)  return 0;

    int &ret = dp[i][stage];
    if(ret != -1)   return ret;

    /// Continue with the same stage
    int ans1;
    if(stage == 0)  ans1 = sol(i+1, 0);
    if(stage == 1)  ans1 = a[i] + sol(i+1, 1);

    /// Switch to the next stage
    int ans2 = sol(i, stage+1);

    return ret = max(ans1, ans2);
}

int solution(vector<int> &A)
{
    n = A.size();
    int mx = A[0];
    for(int i = 0; i < n; i++)  a[i] = A[i], mx = max(mx, A[i]);

    if(mx < 0)  return mx;

    memset(dp, -1, sizeof(dp));
    return sol(0, 0);
}

