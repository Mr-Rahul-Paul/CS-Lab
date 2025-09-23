#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxCrossingSum(vector<int> &a, int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + a[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++)
    {
        sum = sum + a[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    if (left_sum == INT_MIN)
        return right_sum;
    if (right_sum == INT_MIN)
        return left_sum;

    return left_sum + right_sum;
}

int maxSubArraySum(vector<int> &a, int l, int h)
{
    if (l == h)
        return a[l];

    int m = (l + h) / 2;

    return max({maxSubArraySum(a, l, m),
                maxSubArraySum(a, m + 1, h),
                maxCrossingSum(a, l, m, h)});
}

int MCSM(vector<int> &v)
{
    int n = v.size();

    int normalMax = maxSubArraySum(v, 0, n - 1);
    
    return normalMax;

    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += v[i];
        v[i] = -v[i];
    }

    int minSub_inverted = maxSubArraySum(v, 0, n - 1);

    int circularMax = total_sum - (-minSub_inverted);

    return max(normalMax, circularMax);
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = MCSM(a);
    cout << ans << endl;
}

int main()
{

    solve();

    return 0;
}
