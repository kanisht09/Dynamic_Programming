#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
using namespace std;

#define F(i,a,n) for(ll i=a;i<n;i++)
#define ll long long


// Count the number of subsets with given difference
// Problem link : https://leetcode.com/problems/target-sum/

// S1-S2=d
// S1+S2=S
// S1=(S+d)/2

// so just count the number of subsets with sum (S+d)/2
// where S=sum of array and d is the difference

// Bottom Up
ll dp[102][100002];
ll wt[102];
ll n, W;
ll diff;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> diff;
    W = 0;
    F(i, 0, n)
    {
        cin >> wt[i];
        W += wt[i];
    }
    ll k = (W + diff);
    if (k % 2 || W < diff)
    {
        cout << 0 << "\n";
    }
    else
    {
        F(i, 1, W + 1)
        {
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        F(i, 1, n + 1)
        {
            if (wt[i - 1] == 0)
            {
                dp[i][0] = 2 * dp[i - 1][0];
            }
            else
            {
                dp[i][0] = dp[i - 1][0];
            }
        }
        F(i, 1, n + 1)
        {
            F(j, 1, W + 1)
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
        k >>= 1;
        cout << dp[n][k] << "\n";
    }

    return 0;

}