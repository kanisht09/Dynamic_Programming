#include <bits/stdc++.h>
#define INF 1e9
#define ll long long int
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
using namespace std;

//Bottom Up

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
    cout<<dp[n][W]<<"\n";



    return 0;

}
