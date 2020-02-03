/// DP - State Graphs

/** Idea

dp[state] = 1 if this state is reachable from the initial state.

For subset problems: Think of each element as an edge that
                     can cause transition from one state to another.
*/

/** Knapsack

State: {Remaining capacity, Total price}
Initial state: {capacity, 0}

Element: {w, p}     {remCapacity, price} ==> {remCapacity-w[i], price+p[i]}

Example:
capacity = 10
index:    0  1  2
weight:   5   2  4
price:    150 20 50

answer = maximum totalPrice for any reachable state
*/

#define MAXC (Largest possible value for capacity + 9)
#define MAXP (Largest possible value for totalPrice + 9)
bool dp[MAXC][MAXP];    ///O(MAXC * MAXP) memory

dp[capacity][0] = true;

///O(n * MAXC * MAXP) time
for(int i = 0; i < n; i++)      //Loop over items (edges)
{
    for(int remCapacity = 0; remCapacity < MAXC; remCapacity++)
        for(int totalPrice = 0; totalPrice < MAXP; totalPrice++)
            if(dp[remCapacity][totalPrice])
            {
                if(remCapacity < w[i])  continue;
                dp[remCapacity - w[i]][totalPrice + p[i]] = 1;
            }
}

/** Optimizations
1. Loop only over reachable states
    >> Will not always give you a boost

2. Transform totalPrice from DP parameter to DP value!
    1- It doesn't affect the take/leave decision
    2- We want to maximize it

dp[remCapacity][totalPrice] = 1*(state {remCapacity, totalPrice} is reachable)
dp[remCapacity] = Maximum totalPrice for any reachable state with the given remCapacity

Answer = max(dp[remCapacity]) over all reachable states
*/


/// SPOJ "The Knapsack Problem"
#define MAXC 2009
int dp[MAXC];           ///O(MAXC) memory!
int w[2009], p[2009];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int capacity, n;  cin >> capacity >> n;
    loop(n) cin >> w[i] >> p[i];

    ///O(n*capacity) time
    for(int i = 0; i < n; i++)      // For each item (edge)
        //for(int remCapacity = 0; remCapacity <= capacity; remCapacity++)
        for(int remcapacity = 10; remcapacity >= 0; remcapacity--)
        {
            // If I take the element i from the current state
            // Can this transition improve the solution of the next state?
            if(remCapacity < w[i])  continue;
            dp[remCapacity - w[i]] = max(dp[remCapacity - w[i]], dp[remCapacity]+p[i]);
        }

    int ans = 0;
    for(int remCapacity = 0; remCapacity <= capacity; remCapacity++) ans = max(ans, dp[remCapacity]);

    cout << ans << endl;
    return 0;
}

///Advantage?
- Many problems are easier to think of this way
- More memory efficient (table method)

/// Repetitions??
- With repitions
- BUGS!
- Bounded repitions


0   1   2   3   4   5   6   7   8   9   10
300                 150                 0


/** CF 837D
You have an array of n numbers.
You need to choose a subset of exactly k numbers so that the number of trailing zeros of
the product of the selected numbers will be maximum possible.
1 <= k <= n <= 200

Example:
5 3
15 16 3 25 9

answer = 3      (15*16*25 = 6000)

State = {numTaken, twos, fives}
Element = {t, f}
Transition:     {numTaken, twos, fives} ==> {numTaken+1, twos+t, fives+f}
Answer = min(twos, fives), maximize over all reachable states with numTaken = k

Transform "twos" from DP parameter to DP value!
dp[numTaken][fives] = Maximum number of twos that I can get from "numTaken" elements such that
                      they contain the given number of "fives"

Answer = min(fives, dp[k][fives]), loop over all values of "fives" and maximize.
*/

int dp[209][6000];

int main()
{
    int n, k;   cin >> n >> k;

    // You should usually set all states as unreachable!
    // dp[numTaken = 0][fives = 10] = 0 is not acceptable!
    for(int numTaken = 0; numTaken < n; numTaken++)
        for(int fives = 0; fives < 6000; fives++)
            dp[numTaken][fives] = -1e9;

    dp[0][0] = 0;       //Only the initial state is reachable

    for(int i = 0; i < n; i++)
    {
        ll a;  cin >> a;
        int t = 0, f = 0;
        while(a%2 == 0)     t++, a /= 2;
        while(a%5 == 0)     f++, a /= 5;

        for(int numTaken = n; numTaken >= 0; numTaken--)
        {
            for(int fives = 0; fives < 6000; fives++)   if(dp[numTaken][fives] != -1e9)
            {
                dp[numTaken+1][fives+f] = max(dp[numTaken+1][fives+f], t+dp[numTaken][fives]);
            }
        }
    }

    int ans = 0;
    for(int fives = 0; fives < 6000; fives++)   ans = max(ans, min(fives, dp[k][fives]));
    cout << ans << endl;
    return 0;
}
