#include <bits/stdc++.h>
using namespace std;

/** Idea
Assign one color for all prime numbers, and another color for all composite numbers.
*/

int main()
{
	int n;  cin >> n;
	n++;    //Now, the prices are 2,3,...,n (not n+1)

	//Sieve
    vector<bool> isPrime(n+9, 1);
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i])
        {
            for(int j = 2*i; j <= n; j += i)     isPrime[j] = false;
        }
    }


    if(n <= 3)      cout << "1" << endl;    //No composite numbers <= 3, so we need only 1 color
    else            cout << "2" << endl;

    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i])  cout << "1 ";
        else            cout << "2 ";
    }
	return 0;
}

