    #include <bits/stdc++.h>
    using namespace std;

    int LC(const string &word1, const string &word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        
        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= n; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j],
                                        dp[i][j - 1],
                                        dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n];
    }

    int main()
    {
        string w1, w2;
        if (!(cin >> w1 >> w2))
            return 0;
        cout << LC(w1, w2) << '\n';
        return 0;
    }
