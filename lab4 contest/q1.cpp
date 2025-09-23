#include <iostream>
#include <vector>
#define strtoint(x) atoll(x.c_str())
#define inttostr(x) to_string(x);
#define inttobi(n) bitset<64>(n).to_string()
#define bitoint(x) a(x);
// #define int long long
#define MOD 1000000007

using namespace std;
// rercusive soln
/*
int recur(int c, vector<int>& arr, vector<int>& dp) {
    
if (c >= arr.size()) return 0;

    if (dp[c] != -1) return dp[c];

    int take = arr[c] + recur(c + 2, arr, dp);
    int leave = recur(c + 1, arr, dp);

    return dp[c] = max(take, leave);
}

int solve() {
    int a;
    cin >> a;
    vector<int> arr(a);
    for (int t = 0; t < a; t++) cin >> arr[t];

    vector<int> dp(a, -1);
    cout << recur(0, arr, dp);
    return 0;
}
*/

// dp soln
/*
int recur(int i , vector<int>& arr, vector<int>& dp){
    if (i>=arr.size()) return 0 ;
    if (dp[i] != -1) return dp[i];
    int take = arr[i] + recur(i+2 , arr, dp) ;
    int leave = recur(i+1 , arr, dp) ;
    dp[i] = max(take , leave ) ;
    return dp[i] ;
}
int    solve(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(n , -1) ;
    int ans = recur(0, arr , dp);
    cout << ans;
    return 0;
}
*/

// tab
int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(n, 0);
    dp[n - 1] = arr[n - 1];
    dp[n - 2] = max(arr[n - 1], arr[n - 2]);
    for (int i = n - 3; i >= 0; i--)
    {
        int take = arr[i] + dp[i + 2];
        int leave = dp[i + 1];
        dp[i] = max(take, leave);
    }
    cout << dp[0];
    return 0;
}

// iterative
// int solve()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);  
//     for (int q = 0; q < n; q++)
//     {
//         cin >> arr[q];
//     }
//     int next = 0;     // dp[i+1]
//     int next2 = 0; // dp[i+2]
//     int curr = 0;

//     for (int c = n - 1; c >= 0; c--)
//     {
//         int take = arr[c] + next2;
//         int skip = next;
//         curr = max(take, skip);

//        
//         next2 = next;
//         next = curr;
//     }

//     cout << curr << endl;
//     return 0;
// }
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    while (tc--)
    {
        solve();
        cout << endl;
    }
}