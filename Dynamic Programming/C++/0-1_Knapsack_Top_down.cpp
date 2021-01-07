#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
using namespace std;

#define ll long long


// Problem Link :https://atcoder.jp/contests/dp/tasks/dp_d


// Top down
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



    cout << dp[n][W] << "\n";

    return 0;

}
