
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> g(const vector<pair<int,int>> &p, int n)
{
    vector<int> D(n);
    for (int j = 0; j < n; j++)
    {
        D[j] = (p[j].first * p[j].first + p[j].second * p[j].second);
    }
    return D;
}

int part(vector<pair<int,int>> &P, vector<int> &D, int l, int r)
{
    int pv = D[l];
    int L = l;
    int R = r;
    while (L < R)
    {
        while (D[L] <= pv && L <= r - 1) L++;
        while (D[R] > pv && R >= l + 1) R--;
        if (L < R)
        {
            swap(D[L], D[R]);
            swap(P[L], P[R]);
        }
    }
    swap(D[l], D[R]);
    swap(P[l], P[R]);
    return R;
}

void f(vector<pair<int,int>> &P, vector<int> &D, int l, int r, int t)
{
    if (l < r)
    {
        int pi = part(P, D, l, r);
        if (pi == t - 1) return;
        else if (pi < t - 1) f(P, D, pi + 1, r, t);
        else f(P, D, l, pi - 1, t);
    }
}

void solve()
{
    int n, t;
    cin >> n >> t;
    vector<pair<int,int>> P;
    for (int j = 0; j < n; j++)
    {
        int x, y;
        cin >> x >> y;
        P.push_back({x, y});
    }
    vector<int> D = g(P, n);
    f(P, D, 0, n - 1, t);

    vector<pair<int,int>> C;
    for (int j = 0; j < t; j++) C.push_back(P[j]);

    sort(C.begin(), C.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    for (int j = 0; j < t; j++)
    {
        cout << C[j].first << " " << C[j].second << endl;
    }
}

int main()
{
    int tc = 1;
    while (tc--)
    {
        solve();
        cout << endl;
    }
    return 0;
}   
