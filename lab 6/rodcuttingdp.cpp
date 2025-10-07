#include <bits/stdc++.h>
using namespace std;

int RC(int len[], int price[], int n, int N, int cuts)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(N + 1, vector<int>(cuts + 1, 0)));

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            for (int k = 0; k <= cuts; ++k)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    dp[i][j][k] = 0;
                }
                else if (len[i - 1] <= j)
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], price[i - 1] + dp[i][j - len[i - 1]][k - 1]);
                }
                else
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
    }
    return dp[n][N][cuts];
}

int main()
{
    int price[] = {2, 5, 7, 8, 10};
    int len[] = {1, 2, 3, 4, 5};
    int N = 5;
    int n = 5;
    int pieces = 2;

    cout << RC(len, price, n, N, pieces) << endl;

    return 0;
}