#include <iostream>

using namespace std;

int findPeak(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int countLessEqual(int arr[], int n, int peak, int target)
{
    int count = 0;

    for (int i = 0; i <= peak; i++)
    {
        if (arr[i] <= target)
            count++;
    }

    for (int i = peak + 1; i < n; i++)
    {
        if (arr[i] <= target)
            count++;
    }

    return count;
}

int findMin(int arr[], int n, int peak)
{
    int minVal = arr[0];
    if (n > 1 && arr[n - 1] < minVal)
        minVal = arr[n - 1];
    return minVal;
}

int findMax(int arr[], int peak)
{
    return arr[peak];
}

int findKthElement(int arr[], int n, int peak, int k)
{
    int values[1000];
    int valueCount = 0;

    for (int i = 0; i < n; i++)
    {
        int exists = 0;
        for (int j = 0; j < valueCount; j++)
        {
            if (values[j] == arr[i])
            {
                exists = 1;
                break;
            }
        }
        if (!exists)
        {
            values[valueCount++] = arr[i];
        }
    }

    int result = -1;
    for (int i = 0; i < valueCount; i++)
    {
        int lessCount = 0;
        int equalCount = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] < values[i])
                lessCount++;
            else if (arr[j] == values[i])
                equalCount++;
        }

        if (lessCount < k && lessCount + equalCount >= k)
        {
            if (result == -1 || values[i] < result)
                result = values[i];
        }
    }

    return result;
}

int findMedianDivideConquer(int arr[], int n)
{
    int peak = findPeak(arr, n);
    int k = (n + 1) / 2;

    int low = findMin(arr, n, peak);
    int high = findMax(arr, peak);
    int result = low;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = countLessEqual(arr, n, peak, mid);

        if (count < k)
        {
            low = mid + 1;
        }
        else
        {
            result = mid;
            high = mid - 1;
        }
    }

    int closestElement = arr[0];
    int minDiff = 1000000;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= result)
        {
            int diff = arr[i] - result;
            if (diff < minDiff)
            {
                minDiff = diff;
                closestElement = arr[i];
            }
        }
    }

    return findKthElement(arr, n, peak, k);
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

    int median = findMedianDivideConquer(arr, n);
    cout << median << endl;

    return 0;
}