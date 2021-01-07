#include <bits/stdc++.h>
#define ll long long int
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
using namespace std;

//Top Down

// Problem link : https://www.codechef.com/problems/MARCHA1
// Equal sum partition
// Problem link : https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

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

    int t;
    cin >> t;
    while (t--)
    {
        // dp[i][j] for ith element is wt j present
        cin >> n >> W;
        for (ll i = 0; i < n; i++)
        {
            cin >> wt[i];
        }
        for (ll i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        // here be careful start from w=1 not from w=0 i.e i should start from 1 not from 0
        for (ll i = 1; i <= W; i++)
        {
            dp[0][i] = 0;
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= W; j++)
            {
                if (wt[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - wt[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][W])cout << "Yes\n";
        else
            cout << "No\n";

    }

    return 0;

}