#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::reverse and std::max

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1;
    cin >> s1;
    
    if (s1.length() == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    
    int n = s1.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } 
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[n][n] << endl;
    
    return 0;
}