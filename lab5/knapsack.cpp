#include <bits/stdc++.h>
using namespace std;

int KSrecur(int wt[], int val[], int n, int W)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return KSrecur(wt, val, n - 1, W);
    return max(val[n - 1] + KSrecur(wt, val, n - 1, W - wt[n - 1]), KSrecur(wt, val, n - 1, W));
}


int KSmemo(int wt[], int val[], int n, int W, vector<vector<int>> &dp)
{
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    if (wt[n - 1] > W)
        return dp[n][W] = KSmemo(wt, val, n - 1, W, dp);
    return dp[n][W] = max(val[n - 1] + KSmemo(wt, val, n - 1, W - wt[n - 1], dp), KSmemo(wt, val, n - 1, W, dp));
}

int KStab(int wt[], int val[], int n, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

 
    cout << "Tabular: " << KStab(wt, val, n, W) << endl;

    return 0;
}