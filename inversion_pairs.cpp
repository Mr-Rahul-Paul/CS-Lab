    /*
    logic used :
        check every pair (i < j) and count when arr[i] > arr[j]
        use merge to count cross inversions in O(n log n)
    */
    #include <bits/stdc++.h>    

    using namespace std;

    long long mergeNcount(vector<int> &arr, int left, int mid, int right)
    {
        long long inv = 0;

        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
                inv += (n1 - i); // count left elements > [j-1]
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }

        return inv;
    }

    long long sort_count(vector<int> &arr, int left, int right)
    {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        long long inv = 0;
        inv += sort_count(arr, left, mid);
        inv += sort_count(arr, mid + 1, right);
        inv += mergeNcount(arr, left, mid, right);
        return inv;
    }

    int main()
    {
        vector<int> a = {3, 8, 12, 5, 6};
        long long ans = sort_count(a, 0, a.size() - 1);
        cout << ans << endl; // 4
        return 0;
    }