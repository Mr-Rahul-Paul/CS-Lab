#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define strtoint(x) atoll(x.c_str())
#define inttostr(x) to_string(x);
#define inttobi(n) bitset<64>(n).to_string()
#define bitoint(x) a(x);

using namespace std;

// recursionsive soln
/*
int recursion(int i, bool t, vector<int>& arr, vector<vector<int>>& dp) {
    if (i >= arr.size()) {
        return t ? INT_MIN : 0;
    }

    if (dp[i][t] != INT_MIN) {
        return dp[i][t];
    }

    int take = arr[i] + recursion(i + 1, false, arr, dp);

    int leave = t ? INT_MIN : recursion(i + 1, true, arr, dp);

    return dp[i][t] = max(take, leave);
}

int solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, INT_MIN));

    int ans = recursion(0, true, arr, dp);


    if (ans == INT_MIN) {
        ans = *max_ele(arr.begin(), arr.end());
    }

    cout << ans;
    return 0;
}
*/

// dp soln
/*
int recursion(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if (i > j) return INT_MIN;

    if (dp[i][j] != INT_MIN) return dp[i][j];


    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += arr[k];
    }

    return dp[i][j] = sum;
}

int solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    int ms = INT_MIN;


    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ms = max(ms, recursion(i, j, arr, dp));
        }
    }

    cout << ms;
    return 0;
}
*/

// tab soln
int solve()
{
    int q;
    cin >> q;
    vector<int> li(q);
    for (int cnt = 0; cnt < q; cnt++)
    {
        cin >> li[cnt];
    }
    //dp[i] = max(li[i], dp[i-1] + li[i])
    vector<int> dp(q);
    dp[0] = li[0];
    int peakSum = dp[0];

    for (int i = 1; i < q; i++)
    {
        dp[i] = max(li[i], dp[i - 1] + li[i]);
        peakSum = max(peakSum, dp[i]);
    }

    cout << peakSum;
    return 0;
}

// iterative soln
// int solve()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//
//     int maxSoFar = arr[0];
//     int maxEndingHere = arr[0];
//
//     for (int i = 1; i < n; i++)
//     {
//         maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
//         maxSoFar = max(maxSoFar, maxEndingHere);
//     }
//
//     cout << maxSoFar;
//     return 0;
// }

signed main()
{
    int tc = 1;
    while (tc--)
    {
        solve();
        cout << endl;
    }
}
