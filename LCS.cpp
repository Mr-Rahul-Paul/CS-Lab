#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

void printlcs(vector<vector<int>>& dp, string s1, string s2, int n, int m) {
     
    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if ( s1[i - 1] == s2[j - 1] ) {
            lcs += s1[i - 1];
            i--;
            j--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } 
        else {
            j--;
        }   
    }
    
    
    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    int n = s1.length();
    int m = s2.length();
    //memo 
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } 
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printlcs( dp,  s1, s2,  n,  m);
    cout <<"size of lcs max"<<  dp[n][m] << endl;
    return 0;
}