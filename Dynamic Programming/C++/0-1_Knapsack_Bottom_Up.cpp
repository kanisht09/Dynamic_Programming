#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
using namespace std;

#define ll long long


// Problem Link :https://atcoder.jp/contests/dp/tasks/dp_d


// Bottom Up
ll dp[102][100002];
ll val[102];
ll wt[102];
ll n, W;


int main()
{

#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin >> n >> W;
    for (ll i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][W] << "\n";

    return 0;

}
