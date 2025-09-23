#include <iostream>

using namespace std;

int cutRod(int price[], int n)
{
    if (n <= 0)
        return 0;
    int max_val = -1;
    for (int i = 1; i <= n; i++)
    {
        int val = price[i - 1] + cutRod(price, n - i);
        if (val > max_val)
            max_val = val;
    }
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
    cout << cutRod(price, n) << endl;
    return 0;
}
