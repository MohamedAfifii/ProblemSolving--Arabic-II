#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n;
  cin >> n;

  // the biggest number in the array
  int maximum = 10 * 1000 * 1000;

  // frequency of each number
  vector<int> cnt(maximum + 1);
  
  for (int i = 0; i < n; ++i)
  {
    int x;
    cin >> x;
    cnt[x]++;
  }

  // calculate the answer for each prime <= 10^7
  // ans[p] = number of elements divisible by p and p is prime
  vector<int> ans(maximum + 1);
  vector<bool> not_prime(maximum + 1);

  for (int i = 2; i <= maximum; ++i)
  {
    if (not_prime[i])
    {
      continue;
    }
    
    for (int j = i; j <= maximum; j += i)
    {
      ans[i] += cnt[j];
      not_prime[j] = true;
    }
  }

  // do prefix sum over ans
  // this way ans[p] = answer for all primes <= p
  partial_sum(ans.begin(), ans.end(), ans.begin());

  int m;
  cin >> m;
  while (m--)
  {
    int l, r;
    cin >> l >> r;

    // l, r can be very big but we only care about values <= 10^7
    l = min(l, maximum);
    r = min(r, maximum);

    // from inclusion exclusion principle
    cout << ans[r] - ans[l - 1] << '\n';
  }
}
