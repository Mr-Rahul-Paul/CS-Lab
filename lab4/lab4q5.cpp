#include <iostream>

using namespace std;

void Swap(int &p, int &t)
{
    int k = p;
    p = t;
    t = k;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] >= pivot)
        {
            i++;
            Swap(arr[i], arr[j]);
        }
    }
    Swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int pi = partition(arr, low, high);

        if (pi == k - 1)
        {
            return arr[pi];
        }
        else if (pi > k - 1)
        {
            return quickSelect(arr, low, pi - 1, k);
        }
        else
        {
            return quickSelect(arr, pi + 1, high, k);
        }
    }
    return -1;
}

int countElementsInTopPercent(int arr[], int n, int per)
{
    int temp[1000];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }

    int topCount = (per * n + 99) / 100;

    if (topCount == 0)
    {
        return 0;
    }

    if (topCount >= n)
    {
        return n;
    }

    int threshold = quickSelect(temp, 0, n - 1, topCount);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= threshold)
        {
            count++;
        }
    }

    if (count > topCount)
    {
        int strictCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > threshold)
            {
                strictCount++;
            }
        }
        count = strictCount + (topCount - strictCount);
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int per;
    cin >> per;

    int result = countElementsInTopPercent(arr, n, per);
    cout << result << endl;

    return 0;
}
