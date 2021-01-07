#include <bits/stdc++.h>
#define INF 1e9
#define ll long long int
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
using namespace std;

//Bottom Up

// Minimum subset sum difference
// Exactly same as subset sum
// Just for the last row j->(0-sum)
// check which subset sum is possible and take minimum of sum-2*j

// Just a variation of 0-1 Knapsack


ll wt[25];
ll n, W;
int dp[25][20005];


int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
        sum += wt[i];
    }
    W = sum;
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= W; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - wt[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    ll mini = INF;
    for (ll i = 0; i <= W; i++)
    {
        if (dp[n][i])
            mini = min(mini, abs(sum - 2 * i));
    }
    cout << mini << "\n";



    return 0;

}