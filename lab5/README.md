# Knapsack Problem - Time Complexity Analysis

This project implements the 0/1 Knapsack problem using Dynamic Programming and measures execution time across different input sizes to analyze time complexity.

## Files Overview

- `knapsack_timing.cpp` - Main C++ program with DP implementation and timing measurement
- `plot_results.py` - Python script to visualize timing results
- `Makefile` - Build automation
- `README.md` - This file

## Features

### Algorithms Implemented
1. **2D Dynamic Programming**: Traditional approach using a 2D table
2. **1D Dynamic Programming**: Space-optimized version using only 1D array

### Time Complexity Analysis
- Tests array sizes from 100 to 500 items (increments of 50)
- Measures execution time using `std::chrono::high_resolution_clock`
- Generates CSV output for further analysis
- Both algorithms have O(n × W) time complexity where n = number of items, W = knapsack capacity

## How to Run

### Method 1: Using Makefile (Recommended)
```bash
# Compile and run the timing analysis
make run

# Compile, run, and generate plots
make plot

# Clean generated files
make clean
```

### Method 2: Manual Compilation
```bash
# Compile
g++ -std=c++17 -O2 -Wall -o knapsack_timing knapsack_timing.cpp

# Run
./knapsack_timing

# Generate plots (optional)
python3 plot_results.py
```

## Output

### Console Output
- Real-time results showing execution times for each array size
- Comparison between 2D and 1D DP approaches
- Verification that both algorithms produce identical results

### Generated Files
- `knapsack_timing_results.csv` - Raw timing data in CSV format
- `knapsack_timing_graph.png` - Visual plot of timing results (if Python script is run)

## Understanding the Results

### Expected Behavior
- **Time Complexity**: O(n × W) for both algorithms
- **Space Complexity**: 
  - 2D DP: O(n × W)
  - 1D DP: O(W)
- **Performance**: 1D DP is typically faster due to better cache locality

### Test Data Generation
- Random weights: 1-50 units
- Random values: 1-100 units  
- Knapsack capacity: ~30% of total weight (realistic scenario)

## Key Features of the Implementation

### Chrono Usage
```cpp
auto start = high_resolution_clock::now();
algorithm(capacity, weights, values, n);
auto end = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(end - start);
```

### Dynamic Programming Logic
```cpp
// 2D DP recurrence relation
if (weights[i-1] <= w) {
    dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
} else {
    dp[i][w] = dp[i-1][w];
}
```

## Requirements

### C++ Compilation
- C++17 compatible compiler (g++, clang++)
- Standard library with chrono support

### Python Visualization (Optional)
- Python 3.x
- pandas: `pip install pandas`
- matplotlib: `pip install matplotlib`
- numpy: `pip install numpy`

## Time Complexity Graph Interpretation

When you run the complete analysis, you'll see:
1. **Linear Growth**: Time increases roughly linearly with problem size
2. **Consistent Performance**: Both algorithms show similar growth patterns
3. **Optimization Effect**: 1D DP often performs better due to memory access patterns

This analysis helps demonstrate that the theoretical O(n × W) complexity holds in practice!
