int dp[100009];

int solution(vector<int> &A) 
{
    int n = A.size();
    for(int i = 0; i < n; i++)  dp[i] = -1e9;
    dp[n-1] = A[n-1];
    
    for(int i = n-2; i >= 0; i--)
    {
        for(int step = 1; step <= 6; step++)    if(i+step <= n-1)
        {
            dp[i] = max(dp[i], A[i]+dp[i+step]);  
        }
    }
    
    return dp[0];
}

