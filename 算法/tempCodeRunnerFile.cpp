// 可切割的背包问题

/// 问题描述：给定n件物品，每件物品的重量和价值分别为w[i]和v[i]，背包的容量为W。求解将哪些物品装入背包，可使价值总和最大。物品可以切割

//1.录入每一个金属价值和重量，计算价值比
//2.降序价值比排序
//3.依次装入物品

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Metal{
    int weight;
    int value;
    double ratio;
};

//快速排序
int partition(Metal metal[], int low, int high){
    double pivot = metal[high].ratio;
    int i = (low - 1);  //初始时指向第一个元素的左边

    for(int j = low; j <= high - 1; j++){
        if(metal[j].ratio > pivot){  // 排序为降序
            i++;
            swap(metal[i], metal[j]);   
        }
    }
    swap(metal[i + 1], metal[high]);
    return (i + 1);
}

void quickSort(Metal metal[], int low, int high){
    if(low < high){
        int pivot = partition(metal, low, high);
        quickSort(metal, low, pivot - 1);
        quickSort(metal, pivot + 1, high);
    }
}

int main(){
    int n, V;   //n种金属，口袋大小为V
    scanf("%d%d", &n, &V);
    Metal metal[n+1];

    //录入信息
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &metal[i].weight, &metal[i].value);
        metal[i].ratio = static_cast<double>(metal[i].value) / metal[i].weight;
    }

    quickSort(metal, 1, n);

    // //输出metal
    // for(int i = 1; i <= n; i++){
    //     printf("%d %d %.2f\n", metal[i].weight, metal[i].value, metal[i].ratio);
    // }
    //装入背包
    double sumValue = 0.0;
    for(int i = 1; i <= n; i++){
        if(V >= metal[i].weight){
            V -= metal[i].weight;
            sumValue += metal[i].value;
        }else{
            sumValue += metal[i].ratio * V;     //装满剩下的空间
            break;
        }
    }

    printf("%d", int(sumValue));


    return 0;
}




/*
3 4
1 10
2 100
3 300
*/
