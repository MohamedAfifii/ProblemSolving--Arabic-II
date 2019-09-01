#include <bits/stdc++.h>

#define maxn 100009
int n;
int a[maxn];
int dp[maxn][3];

int sol(int i, int state)
{
    if(state == 3)  return 0;
    if(i == n)  return -1e9; 
    int &ret = dp[i][state];
    if(ret != -1)   return ret;
    
    if(state == 0)
    {
        int ans1 = sol(i+1, 0);
        int ans2 = sol(i+1, 1);
        ret = max(ans1, ans2);
    }
    
    else
    {
        int ans1 = a[i] + sol(i+1, state);
        int ans2 = sol(i+1, state+1);
        ret = max(ans1, ans2);
    }
    
    return ret;
}

int solution(vector<int> &A) 
{
    n = A.size();
    for(int i = 0; i < n; i++)  a[i] = A[i];
    
    memset(dp, -1, sizeof(dp));
    return sol(0, 0);
}
