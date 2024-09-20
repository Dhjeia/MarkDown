#include <iostream>
#include <algorithm> // 用于 std::swap
using namespace std;

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
    int length, index;
    scanf("%d%d", &length, &index);
    int arr[length + 5];
    for(int i = 0; i < length; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, length - 1);
    
    printf("%d\n", arr[index - 1]);

    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high); // 获取分区点

        quickSort(arr, low, pivot - 1); // 对低区递归排序
        quickSort(arr, pivot + 1, high); // 对高区递归排序
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素为基准
    int i = (low - 1); // 小于基准的元素索引

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) { // 如果当前元素比基准小
            i++; // 增加小于基准的元素索引
            swap(arr[i], arr[j]); // 交换元素
        }
    }
    swap(arr[i + 1], arr[high]); // 把基准元素放回到正确位置
    return (i + 1); // 返回基准元素的索引

    
    // int pivot = arr[low];     //pivot选前面，右边指针先出动
    // int j = high;
    // for(int i = high; i >= low; i--){
    //     if(arr[i] > pivot){
    //         j--;
    //         swap(arr[i],arr[j]);
    //     }
    // }
    // swap(arr[low],arr[j-1]);
    // return(j-1);
}
                        