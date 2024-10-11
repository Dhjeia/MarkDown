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

//快速排序
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);  //初始时指向第一个元素的左边

    
    //把所有比pivot小的函数放到左边，所以是放了一个i++
    //排序范围是第一个数到pivot的前一个数字
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);   
        }
    }
    //把所有小数都堆到坐标之后，把pivot放到这些小数的右边
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr,low, high);

        quickSort(arr,low,pivot - 1);
        quickSort(arr,pivot + 1,high);
    }
}