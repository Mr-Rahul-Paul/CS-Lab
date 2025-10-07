#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, max_w, max_v;
vector<int> weights, volumes, values;

vector<vector<vector<int>>> dp;

int solve(int i, int w, int v) {
    if (i == n) {
        return 0;
    }

    if (dp[i][w][v] != -1) {
        return dp[i][w][v];
    }

    int not_taken = solve(i + 1, w, v);

    int taken = 0;
    if (weights[i] <= w && volumes[i] <= v) {
        taken = values[i] + solve(i + 1, w - weights[i], v - volumes[i]);
    }

    // 3. Store the result in the DP table before returning it.
    return dp[i][w][v] = max(taken, not_taken);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> max_w >> max_v;

    weights.resize(n);
    volumes.resize(n);
    values.resize(n);
    
    // Initialize the DP table with dimensions and a default value of -1.
    // Dimensions: n for items, max_w+1 for weights, max_v+1 for volumes.
    dp.resize(n, vector<vector<int>>(max_w + 1, vector<int>(max_v + 1, -1)));

    for (int i = 0; i < n; ++i) cin >> weights[i];
    for (int i = 0; i < n; ++i) cin >> volumes[i];
    for (int i = 0; i < n; ++i) cin >> values[i];

    // Call the function with the initial state (item 0, full capacity).
    cout << solve(0, max_w, max_v) << endl;

    return 0;
}