#include <iostream>

using namespace std;

void Swap(int &p, int &t)
{
    int k = p;
    p = t;
    t = k;
}

void minheapi(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
    {
        smallest = l;
    }

    if (r < n && arr[r] < arr[smallest])
    {
        smallest = r;
    }

    if (smallest != i)
    {
        Swap(arr[i], arr[smallest]);
        minheapi(arr, n, smallest);
    }
}

int min(int ans[], int &hsize)
{
    int root = ans[0];
    ans[0] = ans[hsize - 1];
    hsize--;
    minheapi(ans, hsize, 0);
    return root;
}

void maxheapi(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        Swap(arr[i], arr[largest]);
        maxheapi(arr, n, largest);
    }
}

int extractMax(int arr[], int &heap_size)
{
    int root = arr[0];
    arr[0] = arr[heap_size - 1];
    heap_size--;
    maxheapi(arr, heap_size, 0);
    return root;
}

int main()
{
    int n, k;
    cin >> n >> k;

    // Read all elements from all lists into a single array
    int arr[1000];
    int total_elements = 0;

    for (int i = 0; i < k; i++)
    {
        int list_size;
        cin >> list_size;

        for (int j = 0; j < list_size; j++)
        {
            cin >> arr[total_elements++];
        }
    }

    // Sort the merged array using heap sort
    for (int i = total_elements / 2 - 1; i >= 0; i--)
    {
        maxheapi(arr, total_elements, i);
    }

    int heap_size = total_elements;
    int sorted_arr[1000];
    int sorted_index = 0;
 
    for (int i = 0; i < total_elements; i++)
    {
        sorted_arr[sorted_index++] = extractMax(arr, heap_size);
    }

    // Print elements in ascending order
    for (int i = total_elements - 1; i >= 0; i--)
    {
        cout << sorted_arr[i];
        if (i > 0)
            cout << " ";
    }
    cout << endl;

    return 0;
}
