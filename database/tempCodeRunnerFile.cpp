#include <iostream>
#include <algorithm> // 用于 std::swap
using namespace std;

void maxHeapify(int arr[], int i, int heapSize);
void buildMaxHeap(int arr[], int size);
void heapSort(int arr[], int size);

int main() {
    //int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int length, index;
    scanf("%d%d", &length, &index);
    int arr[length+5];
    for(int i=0;i<length;i++)
        scanf("%d", &arr[i]);
    int size = sizeof(arr) / sizeof(arr[0]);
    
    heapSort(arr, length);
    
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void heapSort(int arr[], int size) {
    buildMaxHeap(arr, size);

    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}

void buildMaxHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i, size);
    }
}

void maxHeapify(int arr[], int i, int heapSize) {
    int l = 2 * i + 1; // 左子节点
    int r = 2 * i + 2; // 右子节点
    int largest = i;

    // 确保左子节点在堆的范围内
    if (l < heapSize && arr[l] > arr[largest]) {
        largest = l;
    }

    // 确保右子节点在堆的范围内
    if (r < heapSize && arr[r] > arr[largest]) {
        largest = r;
    }

    // 如果最大的不是父节点，则交换它们
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // 递归调用 maxHeapify，以确保子树也是大顶堆
        maxHeapify(arr, largest, heapSize);
    }
}
