
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> get_dist(vector<pair<int, int>> points_collection, int num_points)
{
    vector<int> squared_distances(num_points);
    for (int idx = 0; idx < num_points; idx++)
    {
        // formula to get the distance from origin
        // we removed the sqrt to optimise the code and solve approxiamtion issues
        squared_distances[idx] = (points_collection[idx].first * points_collection[idx].first + points_collection[idx].second * points_collection[idx].second);
    }
    return squared_distances;
}

int partition(vector<pair<int, int>> &points_vec, vector<int> &dist_vec, int start_index, int end_index)
{
    int pivot_val = dist_vec[start_index];
    int left_ptr = start_index;
    int right_ptr = end_index;
    while (left_ptr < right_ptr)
    {
        while (dist_vec[left_ptr] <= pivot_val && left_ptr <= end_index - 1)
        {
            left_ptr++;
        }

        while (dist_vec[right_ptr] > pivot_val && right_ptr >= start_index + 1)
        {
            right_ptr--;
        }

        if (left_ptr < right_ptr)
        {
            swap(dist_vec[left_ptr], dist_vec[right_ptr]);
            swap(points_vec[left_ptr], points_vec[right_ptr]);
        }
    }
    swap(dist_vec[start_index], dist_vec[right_ptr]);
    swap(points_vec[start_index], points_vec[right_ptr]);
    return right_ptr;
}

void findIthClosest(vector<pair<int, int>> &arr, vector<int> &dist, int low, int high, int i)
{
    if (low < high)
    {
        int pIndex = partition(arr, dist, low, high);

        if (pIndex == i - 1)
        {
            return;
        }
        else if (pIndex < i - 1)
        {
            findIthClosest(arr, dist, pIndex + 1, high, i);
        }
        else
        {
            findIthClosest(arr, dist, low, pIndex - 1, i);
        }
    }
}

void solve()
{
    int n, i;
    cin >> n >> i;
    vector<pair<int, int>> arr;
    for (int k = 0; k < n; k++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }
    vector<int> dist = get_dist(arr, n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<dist[i]<<endl;
    // }
    findIthClosest(arr, dist, 0, n - 1, i);

    vector<pair<int, int>> closest_points;
    for (int k = 0; k < i; k++)
    {
        closest_points.push_back(arr[k]);
    }

    sort(closest_points.begin(), closest_points.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second; });

    for (int k = 0; k < i; k++)
    {
        cout << closest_points[k].first << " " << closest_points[k].second << endl;
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
}