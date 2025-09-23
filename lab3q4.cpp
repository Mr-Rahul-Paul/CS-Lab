#include <iostream>

using namespace std;

void swp(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void min_heap(int a[], int sz, int i)
{
    int sml = i;
    int l_ch = 2 * i + 1;
    int r_ch = 2 * i + 2;

    if (l_ch < sz && a[l_ch] < a[sml])
    {
        sml = l_ch;
    }

    if (r_ch < sz && a[r_ch] < a[sml])
    {
        sml = r_ch;
    }

    if (sml != i)
    {
        swp(a[i], a[sml]);
        min_heap(a, sz, sml);
    }
}

int get_min(int a[], int &h_sz)
{
    int rt = a[0];
    a[0] = a[h_sz - 1];
    h_sz--;
    min_heap(a, h_sz, 0);
    return rt;
}

void max_heap(int a[], int sz, int i)
{
    int lrg = i;
    int l_ch = 2 * i + 1;
    int r_ch = 2 * i + 2;

    if (l_ch < sz && a[l_ch] > a[lrg])
    {
        lrg = l_ch;
    }

    if (r_ch < sz && a[r_ch] > a[lrg])
    {
        lrg = r_ch;
    }

    if (lrg != i)
    {
        swp(a[i], a[lrg]);
        max_heap(a, sz, lrg);
    }
}

int get_max(int a[], int &h_sz)
{
    int rt = a[0];
    a[0] = a[h_sz - 1];
    h_sz--;
    max_heap(a, h_sz, 0);
    return rt;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int min_arr[25];
    int max_arr[25];

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        min_arr[i] = val;
        max_arr[i] = val;
    }
    // build a min heap
    int min_sz = n;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        min_heap(min_arr, min_sz, i);
    }
    // last element is kth smallest
    int k_sml = 0;
    for (int i = 0; i < k; i++)
    {
        k_sml = get_min(min_arr, min_sz);
    }
    // build a max heap
    int max_sz = n;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heap(max_arr, max_sz, i);
    }
    // last element is kth largest
    int k_lrg = 0;
    for (int i = 0; i < k; i++)
    {
        k_lrg = get_max(max_arr, max_sz);
    }

    cout << k_sml << " " << k_lrg << endl;

    return 0;
}
// bs