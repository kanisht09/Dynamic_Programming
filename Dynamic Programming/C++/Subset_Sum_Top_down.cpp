#include <bits/stdc++.h>
#define ll long long int
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
using namespace std;

//Top Down


// Just a variation of 0-1 Knapsack


ll wt[25];
ll n, W;
int dp[25][20005];

bool subset(ll n, ll W)
{
    if (W == 0)return true;  // 1st condition
    if (n == 0)return false;
    if (dp[n][W] != -1)
        return dp[n][W];
    if (wt[n - 1] <= W)
        return dp[n][W] = subset(n - 1, W)||subset(n - 1, W - wt[n - 1]);
    return dp[n][W] = subset(n - 1, W);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   
        memset(dp, -1, sizeof(dp));
        cin >> n >> W;
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
        }
        subset(n, W);
        if (dp[n][W])cout << "Yes\n";
        else
            cout << "No\n";

    

    return 0;

}
