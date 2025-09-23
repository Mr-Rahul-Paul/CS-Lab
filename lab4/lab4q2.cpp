#include <iostream>

using namespace std;

int cutRod(int price[], int memo[], int n)
{
    if (n <= 0)
        return 0;
    if (memo[n] != -1)
        return memo[n];
    int max_val = -1;
    for (int i = 1; i <= n; i++)
    {
        int val = price[i - 1] + cutRod(price, memo, n - i);
        if (val > max_val)
            max_val = val;
    }
    memo[n] = max_val;
    return max_val;
}

int main()
{
    int n;
    cin >> n;
    int price[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    int memo[1001];
    for (int i = 0; i <= 1000; i++)
        memo[i] = -1;
    cout << cutRod(price, memo, n) << endl;
    return 0;
}
