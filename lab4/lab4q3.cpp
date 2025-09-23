#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int price[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    int dp[1001];
    dp[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        int max_val = -1;
        for (int i = 1; i <= j; i++)
        {
            int val = price[i - 1] + dp[j - i];
            if (val > max_val)
                max_val = val;
        }
        dp[j] = max_val;
    }
    cout << dp[n] << endl;
    return 0;
}
