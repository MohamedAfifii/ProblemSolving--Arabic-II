///DP - Subarrays

/**
Codility MaxSliceSum
Given an array of length n, find the maximum subarray sum in O(n)

n = 9
i:      0  1  2  3  4  5  6  7  8
Ai:     2  1 -10 5  3 -2  4 -9  2       best answer = 5 + 3 + (-2) + 4 = 10
stage:  0  0  0  1  1  1  1  2  2       0: Before, 1: Inside, 2: After

ans = 10
*/

///Solution 1:

#include <bits/stdc++.h>
using namespace std;

#define maxn 1000009
int n;
int a[maxn];
int dp[maxn][2];

/**
sol(i, stage): The maximum subarray sum that I can get from the array A[i:]
               and the given starting stage
*/
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

    //Handle the case where all elements are negative
    //Another way is to modify the dp code to avoid empty subarrays
    //The current version will prefer to stay at stage = 0
    if(mx < 0)  return mx;

    memset(dp, -1, sizeof(dp));
    return sol(0, 0);
}


///Solution 2:

#include <bits/stdc++.h>

#define maxn 1000009
int n;
int a[maxn];
int dp[maxn];

/**
sol(i): The maximum subarray sum that I can get if the subarray is FORCED to start at i
OR: The maximum sum of a subarray that starts at i
*/
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

/**
Codeforces 1155D

Given an array A, you are allowed to multiply a subarray in A by x.
Find the maximum subarray sum.

x = -2
A = -3 8 -2 1 -6    ==>   -3 8 4 -2 12      ==>     ans = 8 + 4 + -2 + 12 = 22

stage: 0 0 0 1 1 2 2 2 3 3 4 4 4 4
*/

#define maxn 300009
int n, x;
ll a[maxn];
ll dp[maxn][5];

ll sol(int i, int stage)
{
    if(i == n || stage == 4)  return 0;     // Empty subarrays are allowed
    ll &ret = dp[i][stage];
    if(ret != -1)   return ret;

    /// Continue with the same stage
    ll ans1;
    if(stage == 0)  ans1 = sol(i+1, 0);
    if(stage == 1)  ans1 = a[i] + sol(i+1, 1);
    if(stage == 2)  ans1 = x*a[i] + sol(i+1, 2);
    if(stage == 3)  ans1 = a[i] + sol(i+1, 3);

    /// Switch to the next stage
    ll ans2 = sol(i, stage+1);

    return ret = max(ans1, ans2);
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> x;
    for(int i = 0; i < n; i++)  cin >> a[i];

    memset(dp, -1, sizeof(dp));
    cout << sol(0, 0) << endl;

    return 0;
}
