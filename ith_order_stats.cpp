#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
/*
logic :
    partitonforpivindex func of QS -> take random index and move it to right -> get piv and compare
    if piv ==k return else look to left and right

    if piv == k we have an answer
*/
int partitonforpivindex(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];

    int i = left - 1;

    for (int j = left; j < right; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}
int IOS(vector<int> &arr, int left, int right, int k)
{
    while (left <= right)
    {
        int RPI = left + rand() % (right - left + 1);

        swap(arr[RPI], arr[right]);

        int pivotIndex = partitonforpivindex(arr, left, right);

        if (pivotIndex == k - 1)
        {
            return arr[pivotIndex];
        }
        else if (pivotIndex > k - 1)
        {
            right = pivotIndex - 1;
        }
        else
        {
            left = pivotIndex + 1;
        }
    }
}
int main()
{
    std::vector<int> a = {10, 4, 5, 8, 6, 11, 26, 3, 2};
    // can loop and haveunlimited tried but idc
    // Find the 3rd smallest element or ith
    int k;
    cout << "enter i , for which i shall return ith smallest element\n";
    cin >> k;
    int ans = IOS(a, 0, a.size() - 1, k);

    cout << ans << endl;
    return 0;
}