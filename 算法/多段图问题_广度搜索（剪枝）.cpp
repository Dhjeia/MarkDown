#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// 定义边的结构体
struct Edge {
    int from, to, weight;
};

// 读取输入并进行动态规划计算
void shortestPathMultiStageGraph(int m, int n, vector<Edge>& edges) {
    // 初始化动态规划表 dp 和前驱节点 predecessor
    vector<long long> dp(m, LLONG_MAX);   // 记录每个节点到终点的最短路径
    vector<int> predecessor(m, -1);       // 记录路径中的前驱节点

    dp[m - 1] = 0; // 汇点 t 的最短路径长度为 0

    // 从倒数第二段开始向前递推，计算每个节点到终点的最短路径
    for (int i = m - 2; i >= 0; i--) {
        for (Edge& edge : edges) {
            if (edge.from == i && dp[edge.to] != LLONG_MAX) {
                long long newCost = edge.weight + dp[edge.to];
                if (newCost < dp[i]) {
                    dp[i] = newCost;
                    predecessor[i] = edge.to;
                }
            }
        }
    }

    // 输出从源点到汇点的最短路径
    vector<int> path;
    for (int v = 0; v != -1; v = predecessor[v]) {
        path.push_back(v);
    }

// 输出路径和路径长度
for (size_t i = 0; i < path.size(); i++) {
    cout << path[i];
    if (i < path.size() - 1) { // 仅在不是最后一个元素时输出空格
        cout << " ";
    }
}
cout << endl;
cout << dp[0] << endl;

}

int main() {
    int m, n;
    cin >> m >> n;

    vector<Edge> edges(n);
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    shortestPathMultiStageGraph(m, n, edges);

    return 0;
}
