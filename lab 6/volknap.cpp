#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, max_w, max_v;
vector<int> weights, volumes, values;

int solve(int i, int w, int v) {
    if (i == n) {
        return 0;
    }

    int not_taken = solve(i + 1, w, v);

    int taken = 0;
    if (weights[i] <= w && volumes[i] <= v) {
        taken = values[i] + solve(i + 1, w - weights[i], v - volumes[i]);
    }

    return max(taken, not_taken);
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> max_w >> max_v;

    weights.resize(n);
    volumes.resize(n);
    values.resize(n);

    for (int i = 0; i < n; ++i) cin >> weights[i];
    for (int i = 0; i < n; ++i) cin >> volumes[i];
    for (int i = 0; i < n; ++i) cin >> values[i];

    cout << solve(0, max_w, max_v) << endl;

    return 0;
}