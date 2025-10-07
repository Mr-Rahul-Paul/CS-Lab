#include <bits/stdc++.h>
using namespace std;

int RC(int len[], int price[], int n, int N, int cuts)
{
    // Base case
    if (n == 0 || N == 0 || cuts == 0)
        return 0;

    if (len[n - 1] <= N)
    {

        int incl = price[n - 1] + RC(len, price, n, N - len[n - 1], cuts - 1);

        int exlc = RC(len, price, n - 1, N, cuts);
        return max(incl, exlc);
    }
    else
    {

        return RC(len, price, n - 1, N, cuts);
    }
}

int main()
{
    int price[] = {2, 5, 7, 8, 10};
    int len[] = {1, 2, 3, 4, 5};
    int N = 5;
    int n = 5;
    int pieces = 2;

    cout << RC(len, price, n, N, pieces) << endl;

    return 0;
}