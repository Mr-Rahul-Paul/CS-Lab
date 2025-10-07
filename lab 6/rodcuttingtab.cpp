#include <bits/stdc++.h>
using namespace std;

int RC(int n, int k, vector<int> &p, vector<vector<int>> &dp)
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = p[i - 1];
    }

    for (int j = 1; j <= k; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[i][j] = 0;

            for (int c = 1; c < i; c++)
            {
                dp[i][j] = max(dp[i][j], p[c - 1] + dp[i - c][j - 1]);
            }
        }
    }
    int max_profit = 0;
    for (int j = 0; j <= k; j++)
    {
        max_profit = max(max_profit, dp[n][j]);
    }

    return max_profit;
}

int main()
{
    int n, k;
    if (!(cin >> n >> k))
        return 0;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    cout << RC(n, k, p, dp) << '\n';
    return 0;
}