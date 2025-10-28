#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int sumoffreq(const vector<int> &freq, int i, int j)
{
    int totalSum = 0;
    for (int k = i; k <= j; k++)
    {
        totalSum += freq[k];
    }
    return totalSum;
}

int OBST(const vector<int> &keys, const vector<int> &freq)
{
    int n = keys.size();
    if (n == 0)
    {
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int s = 1; s <= n; s++)
    {
        for (int i = 0; i <= n - s; i++)
        {
            int j = i + s - 1;

            if (s == 1)
            {
                dp[i][j] = freq[i];
                continue;
            }

            dp[i][j] = INT_MAX;

            for (int r = i; r <= j; r++)
            {
                int left = (r > i) ? dp[i][r - 1] : 0;
                int right = (r < j) ? dp[r + 1][j] : 0;
                int freqsum = sumoffreq(freq, i, j);

                int cost = left + right + freqsum;
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    vector<int> keys = {1, 2, 3};
    vector<int> freq = {10, 20, 30};
    // int ans = OBST;
    int ans = OBST(keys, freq);
    cout << ans;
    return 0;
}