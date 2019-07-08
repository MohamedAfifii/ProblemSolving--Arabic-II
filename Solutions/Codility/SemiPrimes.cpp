
vector<int> solution(int N, vector<int> &P, vector<int> &Q)
{
    int HighestPrimeFactor[N + 1] = {0}; // initialize to zero
    int PrimeCount[N + 1] = {0};         // how many distinct primes in the representation of X

    for (int i = 2; i <= N; ++i)
    {
        if (PrimeCount[i] != 0)
            continue; // not prime
        // if control reaches here, then (i) is a prime
        for (int j = i; j <= N; j += i)
        {                              // move at prime (i) steps
            PrimeCount[j]++;           // increase the number of prime factors
            HighestPrimeFactor[j] = i; // always update (j) with the last / highest prime it has
        }
    }

    vector<int> semiPrimes(N + 1); // primes that has two primes!

    for (int i = 2; i <= N; ++i)
    { // for (i) to be semiPrime
        // i = p * q
        int p = HighestPrimeFactor[i];
        int q = i / p; //
        if (PrimeCount[i] <= 2 && HighestPrimeFactor[q] == q)
            semiPrimes[i] = 1;
    }

    for (int i = 1; i <= N; ++i)
        semiPrimes[i] += semiPrimes[i - 1]; // prefix sum

    vector<int> res((int)P.size());

    for (int i = 0; i < (int)P.size(); ++i)
    {
        res[i] = semiPrimes[Q[i]] - semiPrimes[P[i] - 1]; // patial sum query from [L, R]
    }

    return res;
}