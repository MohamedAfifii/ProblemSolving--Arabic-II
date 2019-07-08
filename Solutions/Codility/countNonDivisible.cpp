vector<int> solution(vector<int> &A)
{

    int N = (int)A.size();
    int MX = N * 2 + 1;

    int frequency[MX] = {0};

    for (auto &x : A)
        frequency[x]++;

    vector<int> res(N);

    for (int i = 0; i < N; ++i)
    {
        int count = 0;
        for (int j = 1; j * j <= A[i]; ++j)
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