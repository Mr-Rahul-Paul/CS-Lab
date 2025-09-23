#include <iostream>

using namespace std;

int freakquency[20];
int answer[20];
int hsize = 0;

void Swap(int &k, int &p)
{
    int t = k;
    k = p;
    p = t;
}

void heapifyDown(int i)
{
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < hsize && freakquency[l] > freakquency[large])
        large = l;

    if (r < hsize && freakquency[r] > freakquency[large])
        large = r;

    if (large != i)
    {
        Swap(freakquency[i], freakquency[large]);
        Swap(answer[i], answer[large]);
        heapifyDown(large);
    }
}

void buildHeap()
{
    int i = (hsize / 2) - 1; // i is index yahape
    for (int g = i; g >= 0; g--)
    {
        heapifyDown(g);
    }
}

void extractMax()
{
    if (hsize <= 0)
        return;

    cout << answer[0] << " ";

    Swap(freakquency[0], freakquency[hsize - 1]);
    Swap(answer[0], answer[hsize - 1]);

    hsize--;
    heapifyDown(0);
}

int main()
{
    int n, k;
    cin >> n >> k;

    int nums[20];
    for (int s = 0; s < n; s++)
    {
        cin >> nums[s];
    }

    int frek[201] = {0};
    for (int i = 0; i < n; i++)
    {
        frek[101 + nums[i]]++;
    }

    
    for (int i = 0; i < 201; i++)
    {
        if (frek[i] > 0)
        {
            freakquency[hsize] = frek[i];
            answer[hsize] = i - 101;
            hsize++;
        }
    }

    buildHeap();

    for (int i = 0; i < k && hsize > 0; i++)
    {
        extractMax();
    }

    cout << endl;

    return 0;
}