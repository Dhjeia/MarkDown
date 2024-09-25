#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
    double ratio; // 价值与重量之比
};

// 比较函数，用于排序
bool compare(Item a, Item b) {
    return a.ratio > b.ratio; // 按照价值与重量比降序排序
}

double fractionalKnapsack(int W, Item items[], int n) {
    // 对物品按照价值与重量比进行排序
    sort(items, items + n, compare);

    double totalValue = 0.0; // 总价值
    for (int i = 0; i < n; i++) {
        if (W == 0) break; // 背包已满
        // 判断当前物品是否可以完全放入背包
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // 不能完全放入，放入部分物品
            totalValue += items[i].value * ((double)W / items[i].weight);
            W = 0; // 背包满了
        }
    }
    return totalValue;
}

int main() {
    // 背包容量
    int W = 10;
    // 物品数量
    const int n = 3;
    // 物品数组
    Item items[n] = {{60, 10, 6.0}, {100, 20, 5.0}, {120, 30, 4.0}}; // 价值、重量和价值与重量比

    double maxValue = fractionalKnapsack(W, items, n);
    cout << "能够取得的最大价值为: " << maxValue << endl;

    return 0;
}
