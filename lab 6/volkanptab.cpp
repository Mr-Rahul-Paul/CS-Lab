#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, max_w, max_v;
    cin >> n >> max_w >> max_v;

    vector<int> weights(n);
    vector<int> volumes(n);
    vector<int> values(n);

    for (int i = 0; i < n; ++i) cin >> weights[i];
    for (int i = 0; i < n; ++i) cin >> volumes[i];
    for (int i = 0; i < n; ++i) cin >> values[i];

    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(max_w + 1,
                                                      vector<int>(max_v + 1, 0)));

    for (int i = 1; i <= n; ++i) {
        // Current item's properties (using i-1 for 0-based vectors)
        int current_w = weights[i - 1];
        int current_v = volumes[i - 1];
        int current_val = values[i - 1];

        // Iterate through all possible weight and volume capacities
        for (int w = 0; w <= max_w; ++w) {
            for (int v = 0; v <= max_v; ++v) {
                int not_taken = dp[i - 1][w][v];

                int taken = 0;
                if (w >= current_w && v >= current_v) {
                    taken = current_val + dp[i - 1][w - current_w][v - current_v];
                }

                dp[i][w][v] = max(taken, not_taken);
            }
        }
    }

    cout << dp[n][max_w][max_v] << endl;

    return 0;
}