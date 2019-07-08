#include<bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char *argv[])
{
 
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    const int mod = 1073741824;
 
    int a, b, c;
    cin >> a >> b >> c;
 
    int N = a * b * c;
 
    vector<int> divisorCount(N + 1, 1);
 
    for(int i = 2; i <= N; ++i)
    {
        if(divisorCount[i] != 1) continue;
        for(int j = i; j <= N; j += i)
        {
            int tmp = j;
            int cnt = 0;
            while(tmp % i == 0 && tmp != 1){
                tmp /= i;
                cnt++;
            }
            divisorCount[j] *= (cnt + 1);
        }
    }
 
    int res = 0;
 
    for(int i = 1; i <= a; ++i)
    {
        for(int j = 1; j <= b; ++j)
        {
            for(int k = 1; k <= c; ++k)
            {
                res += divisorCount[i * j * k];
                if(res >= mod) res -= mod;
            }
        }
    }
 
    cout << res << endl;
   
    return 0;
}