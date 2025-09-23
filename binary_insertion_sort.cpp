#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
logic same as insetion sort but instead of linear to search for correct pos , 
we use BS to get the apt pos
*/

int BS(vector<int> &arr1, int midk, int lower, int high)
{
    if (high <= lower)
        return (midk > arr1[lower]) ? (lower + 1) : lower;

    int mid = (lower + high) / 2;

    if (midk == arr1[mid])
        return mid + 1;

    if (midk > arr1[mid])
        return BS(arr1, midk, mid + 1, high);
    else
        return BS(arr1, midk, lower, mid - 1);
}

void BIS(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int midk = arr[i];
        int j = i - 1;

        // find pos
        int pos = BS(arr, midk, 0, j);

        while (j >= pos)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = midk;
    }
}

void printarr(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Original : ";
    printarr(arr);

    BIS(arr);

    cout << "Sorted : ";
    printarr(arr);
}

int main()
{
    solve();
    return 0;
}
