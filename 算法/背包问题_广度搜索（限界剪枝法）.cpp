#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 定义结构体来保存每个物品的信息（重量和价值）
struct Item {
    long long weight;
    long long value;
    double unitValue; // 单位价值
};

// 定义分支节点结构体，包含当前的层数、总重量、总价值、上界和父节点
struct Node {
    int level;        // 当前节点的层数
    long long weight; // 当前节点的重量
    long long value;  // 当前节点的价值
    double bound;     // 当前节点的上界
    bool operator<(const Node& other) const {
        return bound < other.bound; // 用于优先队列，取最大上界的分支
    }
};

// 计算当前节点的上界函数
double bound(Node u, int n, long long C, vector<Item>& items) {
    if (u.weight >= C) return 0; // 超出容量，返回0作为无效值
    double bound = u.value;
    int j = u.level + 1;
    long long totweight = u.weight;

    // 根据剩余容量，累加计算上界
    while (j < n && totweight + items[j].weight <= C) {
        totweight += items[j].weight;
        bound += items[j].value;
        j++;
    }

    // 如果还有剩余容量但无法完全放下下一个物品，计算分数
    if (j < n) bound += (C - totweight) * items[j].unitValue;

    return bound;
}

// 分支限界法求解01背包
long long knapsack(int n, long long C, vector<Item>& items) {
    // 按照单位价值排序物品
    sort(items.begin(), items.end(), [](Item a, Item b) {
        return a.unitValue > b.unitValue;
    });

    priority_queue<Node> pq;
    Node u, v;
    u.level = -1; u.weight = 0; u.value = 0;
    u.bound = bound(u, n, C, items);
    pq.push(u);

    long long maxValue = 0;

    // 分支限界法核心逻辑
    while (!pq.empty()) {
        u = pq.top();
        pq.pop();

        if (u.bound > maxValue) {
            v.level = u.level + 1;

            // 分支1：加入当前物品
            v.weight = u.weight + items[v.level].weight;
            v.value = u.value + items[v.level].value;
            if (v.weight <= C && v.value > maxValue) {
                maxValue = v.value;
            }
            v.bound = bound(v, n, C, items);
            if (v.bound > maxValue) {
                pq.push(v);
            }

            // 分支2：不加入当前物品
            v.weight = u.weight;
            v.value = u.value;
            v.bound = bound(v, n, C, items);
            if (v.bound > maxValue) {
                pq.push(v);
            }
        }
    }

    return maxValue;
}

int main() {
    int n;
    long long C;
    cin >> n >> C;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
        items[i].unitValue = (double)items[i].value / items[i].weight;
    }

    cout << knapsack(n, C, items) << endl;
    return 0;
}

/*
5 10
10 5
10 2
20 5
30 5
20 4
*/