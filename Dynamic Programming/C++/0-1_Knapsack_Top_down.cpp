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
ll n,W;

ll knapsack(ll W,ll n)
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    if(wt[n-1]<=W)
    {
        return dp[n][W]=max(val[n-1]+knapsack(W-wt[n-1],n-1),knapsack(W,n-1));
    }
    return dp[n][W]=knapsack(W,n-1);
    
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    memset(dp,-1,sizeof(dp));
    cin>>n>>W;
    for(ll i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    knapsack(W,n);
    cout<<dp[n][W]<<"\n";
    
    return 0;
    
}
