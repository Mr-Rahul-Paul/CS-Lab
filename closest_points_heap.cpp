#include <iostream>

using namespace std;
int dist_heap[25];
int pointx[25];
int pointy[25];
int heap_size = 0; // bad me change karege

/*
our logic -> heap banao and print fist i points
*/

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
//  ensure parent is smaller
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    
    if (left < heap_size && dist_heap[left] < dist_heap[smallest])
        smallest = left;

    if (right < heap_size && dist_heap[right] < dist_heap[smallest])
        smallest = right;

        if (smallest != i) {
        swap(dist_heap[i], dist_heap[smallest]);
        swap(pointx[i], pointx[smallest]);
        swap(pointy[i], pointy[smallest]);
        heapifyDown(smallest);
    }
}

void buildHeap() {
   
    int startIdx = (heap_size / 2) - 1;
    for (int k = startIdx; k >= 0; k--) {
        heapifyDown(k);
    }
}

void printmin() {
    if (heap_size <= 0) return;

    cout << pointx[0] << " " << pointy[0] << endl;

    swap(dist_heap[0], dist_heap[heap_size - 1]);
    swap(pointx[0], pointx[heap_size - 1]);
    swap(pointy[0], pointy[heap_size - 1]);
    
    heap_size--;
    heapifyDown(0);
}

int main() {
    int n, i;
    cin >> n >> i;

    for (int k = 0; k < n; k++) {
        cin >> pointx[k] >> pointy[k];
        dist_heap[k] = (int)pointx[k] * pointx[k] + (int)pointy[k] * pointy[k];
    }
    heap_size = n; 

    buildHeap();

    for (int k = 0; k < i; k++) {
        printmin();
    }

    return 0;
}