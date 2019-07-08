/// Prime factorization using Sieve


///Content
///1. Any number has at most one prime factor that is greater than its square root
///2. Prime-power of all numbers from 1 to N factorization using sieve


/** Important fact
"Any number has at most one prime factor that is greater than its square root"
>> Useful for many problems where numbers are large (+Symmetry of divisors)
>> We saw it in Dr. Mustafa's video (factorizing a single integer n)

sqrt(156) = 12.49   >> 156 has at most 1 prime factor > 12.48
156 = 2 * 2 * 3 * 13

O(sqrt(n)) can be much faster than O(n) !!
*********************************************************************************/



/**Prime-power factorization
Factorize all numbers from 1 to N

x = 1176        >> x = 2^3 * 3^1 * 7^2
primeFactorization[x] = {{2,3}, {3,1}, {7,2}}

1. Loop over all numbers from 1 to N and factorize them (forward thinking)
    > Works for N up to 10^5
2. Modify Sieve algorithm
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    vector<vector<pair<int, int>>> primeFactorization(n+1);
    vector<int> numDivisors(n+1, 1);
    vector<bool> isPrime(n+1, true);

    for(int i = 2; i <= n; i++)     if(isPrime[i])
    {
        for(int j = i; j <= n; j += i)
        {
            isPrime[j] = false;

            int cpy = j, cnt = 0;
            while(cpy%i == 0)   cpy /= i, cnt++;

            primeFactorization[j].push_back({i, cnt});
            numDivisors[j] *= (cnt+1);
        }
    }
    //Warning: After this loop, isPrime will not be valid!

    for(int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for(auto p: primeFactorization[i])  cout << "{" << p.first << ", " << p.second << "}, ";
        cout << endl;
    }

    return 0;
}
