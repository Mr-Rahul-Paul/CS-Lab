#include <bits/stdc++.h>
using namespace std;

int LD(string &word1, string &word2, int i, int k, vector<vector<int>> &dp)
{
 
    if (dp[i][k] != -1)
        return dp[i][k];

    if (word1[i - 1] == word2[k - 1])
    {
        return dp[i][k] = LD(word1, word2, i - 1, k - 1, dp);
    }
    else
    {
        int insert = 1 + LD(word1, word2, i - 1, k, dp);
        int del = 1 + LD(word1, word2, i, k - 1, dp);
        int rep = 1 + LD(word1, word2, i - 1, k - 1, dp);
        return dp[i][k] = min({insert, del, rep});
    }
}
int main()
{
    string word1, word2;
    if (!(cin >> word1 >> word2))
        return 0;
    int i = word2.size();
    int k = word1.size();
    vector<vector<int>> dp(i + 1, vector<int>(k + 1, -1));
    cout << LD(word1, word2, i, k, dp) << '\n';
    return 0;
}
