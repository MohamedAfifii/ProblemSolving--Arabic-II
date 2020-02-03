/// DP - Consider what could happen to one element


/** Knapsack
State: {Items, remWeight}

index:    0  1  2
weight:   5   2  4
price:    150 20 50

Rephrase to problem from "Which items to take?" to "Will I take the first item?"
Useful for many problems (especially counting problems)
*/


/** Combinations

By how many ways can you choose a subset of k elements from a set of n elements (nCk)

C(n, k)
Consider one element
- Take  ==> C(n-1, k-1)
- Leave ==> C(n-1, k)
C(n, k) = C(n-1, k-1) + C(n-1, k)

ll C(int n, int k)
{
    if(n == k || k == 0)    return 1;
    if(k == 1)  return n;
    if(c[n][k] != -1)   return c[n][k];

    return C[n][k] = C(n-1, k-1) + C(n-1, k);
}
*/

/** CF 1132F

You are given a string s of length n (1 <= n <= 500).
In one operation you can delete some contiguous substring of the same character.
Calculate the minimum number of operations to delete the whole string.

abcddcbaa ==> abccbaa ==> abbaa ==> aaa ==> {}

answer = 4
*/

int n;
string s;
int dp[509][509];


///sol(i, j): The min number of operations required to delete string s[i:j] (inclusive)
int sol(int i, int j)
{
    if(i == j)  return 1;
    if(i > j)   return 0;

    int &ret = dp[i][j];
    if(ret != -1)   return ret;

    ret = 1 + sol(i+1, j);
    for(int k = i+1; k <= j; k++)   if(s[i] == s[k])
    {
        ret = min(ret, sol(i+1, k-1) + sol(k, j));
    }

    return ret;
}


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> s;
    clr(dp, -1);
    cout << sol(0, n-1) << endl;

    return 0;
}
