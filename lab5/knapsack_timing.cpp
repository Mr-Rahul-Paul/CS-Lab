#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Dynamic Programming solution for 0/1 Knapsack Problem
int knapsackDP(int capacity, vector<int> &weights, vector<int> &values, int n)
{
    // Create a 2D DP table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            if (weights[i - 1] <= w)
            {
                // Max of including or excluding current item
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                // Can't include current item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

// Space-optimized DP solution (using only 1D array)
int knapsackDPOptimized(int capacity, vector<int> &weights, vector<int> &values, int n)
{
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++)
    {
        // Traverse from right to left to avoid using updated values
        for (int w = capacity; w >= weights[i]; w--)
        {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[capacity];
}

// Generate random test data
void generateTestData(int size, vector<int> &weights, vector<int> &values, int &capacity)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> weight_dist(1, 50);
    uniform_int_distribution<> value_dist(1, 100);

    weights.clear();
    values.clear();
    weights.reserve(size);
    values.reserve(size);

    for (int i = 0; i < size; i++)
    {
        weights.push_back(weight_dist(gen));
        values.push_back(value_dist(gen));
    }

    // Set capacity to about 30% of total weight
    int totalWeight = 0;
    for (int w : weights)
    {
        totalWeight += w;
    }
    capacity = totalWeight * 0.3;
    if (capacity == 0)
        capacity = 1;
}

// Measure execution time for a given algorithm
template <typename Func>
double measureTime(Func algorithm, int capacity, vector<int> &weights, vector<int> &values, int n)
{
    auto start = high_resolution_clock::now();
    algorithm(capacity, weights, values, n);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    return duration.count() / 1000.0; // Convert to milliseconds
}

int main()
{
    cout << "Knapsack Problem - Time Complexity Analysis (100 Test Cases)\n";
    cout << "===========================================================\n\n";

    // Create output file for results
    ofstream outFile("knapsack_timing_results.csv");
    outFile << "Size,2D_DP_Time(ms),1D_DP_Time(ms),2D_DP_Result,1D_DP_Result\n";

    cout << left << setw(8) << "Size"
         << setw(15) << "2D DP (ms)"
         << setw(15) << "1D DP (ms)"
         << setw(12) << "2D Result"
         << setw(12) << "1D Result"
         << setw(10) << "Match" << endl;
    cout << string(70, '-') << endl;

    // Test with 100 different arrays (varying sizes from 50 to 1000)
    for (int test = 1; test <= 100; test++)
    {
        // Vary the size linearly from 50 to 1000
        int size = 50 + (test - 1) * 10; // This gives sizes from 50 to 1040

        vector<int> weights, values;
        int capacity;

        // Generate test data
        generateTestData(size, weights, values, capacity);

        // Measure time for 2D DP solution
        double time2D = measureTime(knapsackDP, capacity, weights, values, size);

        // Measure time for 1D DP solution (space optimized)
        double time1D = measureTime(knapsackDPOptimized, capacity, weights, values, size);

        // Get results to verify correctness
        int result2D = knapsackDP(capacity, weights, values, size);
        int result1D = knapsackDPOptimized(capacity, weights, values, size);

        bool match = (result2D == result1D);

        // Display results
        cout << left << setw(8) << size
             << setw(15) << fixed << setprecision(3) << time2D
             << setw(15) << fixed << setprecision(3) << time1D
             << setw(12) << result2D
             << setw(12) << result1D
             << setw(10) << (match ? "✓" : "✗") << endl;

        // Write to CSV file
        outFile << size << "," << time2D << "," << time1D << ","
                << result2D << "," << result1D << endl;
    }

    outFile.close();

    cout << "\nResults saved to 'knapsack_timing_results.csv'\n";
    cout << "\nTime Complexity Analysis:\n";
    cout << "- 2D DP: O(n * W) where n = number of items, W = capacity\n";
    cout << "- 1D DP: O(n * W) but with better space complexity O(W)\n";
    cout << "- Both algorithms have the same time complexity but different space usage\n";

    return 0;
}
