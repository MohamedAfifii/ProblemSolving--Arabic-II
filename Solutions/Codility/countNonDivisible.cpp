vector<int> solution(vector<int> &A)
{

    int N = (int)A.size();
    int MX = N * 2 + 1;

    int frequency[MX] = {0};

    for (auto &x : A)
        frequency[x]++;

    vector<int> res(N);

    for (int i = 0; i < N; ++i) //O(N)
    {
        int count = 0;
        for (int j = 1; j * j <= A[i]; ++j) // O(SQRT(N))
        {
            if (A[i] % j == 0)
            {
                count += frequency[j];
                if (j * j != A[i]) // to avoid double - counting
                    count += frequency[A[i] / j];
            }
        }

        res[i] = N - count;
    }

    return res;
}


// Another Solution O(N.LOG(N))

vector<int> solution(vector<int> &A)
{

    int N = (int)A.size();
    int MX = N * 2 + 1;

    vector<vector<int>> divs(MX);

    // Amortized O(N.LOG(N)) time and O(N.LOG(N)) memory
    for (int i = 1; i < MX; ++i)
    {
        for (int j = i; j < MX; j += i) 
        {
            divs[j].push_back(i);
        }
    }

    int frequency[MX] = {0};

    for (auto &x : A)
        frequency[x]++;

    vector<int> res(N);

    for (int i = 0; i < N; ++i)
    {
        int count = 0;

        for (auto &d : divs[A[i]])
            count += frequency[d];

        res[i] = N - count;
    }

    return res;
}