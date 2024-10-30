#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_CITIES = 100; // 最大城市数量
const int INF = numeric_limits<int>::max(); // 无穷大表示不可达

// 结构体表示节点
struct Node {
    int level;          // 当前深度
    int cost;          // 当前花费
    int bound;         // 当前界限
    int path[MAX_CITIES]; // 当前路径
};

// 计算一个节点的下界
int calculateBound(const int cost[MAX_CITIES][MAX_CITIES], const Node& node, int n) {
    int bound = node.cost;

    // 找到当前路径中最后一个访问的城市
    int lastCity = node.path[node.level - 1];

    // 计算该节点的下界
    for (int i = 0; i < n; ++i) {
        if (i != lastCity && cost[lastCity][i] != INF) {
            bound += cost[lastCity][i];
        }
    }

    // 加上未访问城市的最小边
    for (int i = 0; i < n; ++i) {
        if (node.path[i] == -1) {
            int minEdge = INF;
            for (int j = 0; j < n; ++j) {
                if (cost[i][j] < minEdge) {
                    minEdge = cost[i][j];
                }
            }
            bound += minEdge;
        }
    }

    return bound;
}

// 比较节点的优先队列
struct cmp {
    bool operator()(Node& a, Node& b) {
        return a.bound > b.bound; // 低界限优先
    }
};

// 输出路径的函数
void printPath(const Node& node, int level) {
    for (int i = 0; i <= level; ++i) {
        cout << node.path[i] << (i < level ? " -> " : "\n");
    }
}

// 解决TSP的函数
void tsp(const int cost[MAX_CITIES][MAX_CITIES], int n) {
    // 初始化优先队列
    priority_queue<Node, vector<Node>, cmp> pq;

    Node root;
    root.level = 0;
    root.cost = 0;
    fill(begin(root.path), end(root.path), -1);
    root.path[0] = 0; // 从城市0出发
    root.bound = calculateBound(cost, root, n);
    
    pq.push(root);
    int minCost = INF;

    while (!pq.empty()) {
        Node currentNode = pq.top();
        pq.pop();

        // 如果当前路径的深度达到n，则检查路径成本
        if (currentNode.level == n - 1) {
            // 添加回到起始城市的成本
            int finalCost = currentNode.cost + cost[currentNode.path[n - 1]][0];
            if (finalCost < minCost) {
                minCost = finalCost;
                cout << "Minimum cost: " << minCost << endl;
                // cout << "Path: ";
                // printPath(currentNode, n - 1); // 输出路径
            }
            continue;
        }

        // 进行剪枝
        for (int i = 1; i < n; ++i) {
            if (currentNode.path[i] == -1 && cost[currentNode.path[currentNode.level]][i] != INF) {
                Node newNode = currentNode;
                newNode.level++;
                newNode.path[newNode.level] = i; // 访问城市i
                newNode.cost += cost[currentNode.path[currentNode.level]][i]; // 更新成本
                newNode.bound = calculateBound(cost, newNode, n); // 更新界限

                // 只有当新节点的界限小于当前最小成本时才继续
                if (newNode.bound < minCost) {
                    pq.push(newNode);
                }
            }
        }
    }
}


int main() {
    int cost[MAX_CITIES][MAX_CITIES];

    // 采用二维数组初始化的数据
    int tempCost[MAX_CITIES][MAX_CITIES] = {
        {0, 29, 20, 21},
        {29, 0, 15, 17},
        {20, 15, 0, 28},
        {21, 17, 28, 0}
    };

    // 使用循环赋值
    for (int i = 0; i < MAX_CITIES; ++i) {
        for (int j = 0; j < MAX_CITIES; ++j) {
            cost[i][j] = tempCost[i][j];
        }
    }

    int n = 4; // 这里城市数量固定为4
    tsp(cost, n);

    return 0;
}
