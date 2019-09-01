#include <bits/stdc++.h>

#define maxn 1000009
int n;
int a[maxn];
int dp[maxn];

int sol(int i)
{
    if(i == n)  return -1e9;
    int &ret = dp[i];
    if(ret != -1)   return ret;
    
    ret = max(a[i], a[i]+sol(i+1));
    return ret;
}

int solution(vector<int> &A)
{
    n = A.size();
    for(int i = 0; i < n; i++)  a[i] = A[i];

    memset(dp, -1, sizeof(dp));
    
    int ans = -1e9;
    for(int i = 0; i < n; i++)  ans = max(ans, sol(i));
    return ans;
}

