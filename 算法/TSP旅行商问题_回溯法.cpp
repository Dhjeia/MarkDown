#include <iostream>
#include <climits>
using namespace std;

const int MAX_N = 20; // 假设最多20个城市
int dist[MAX_N][MAX_N]; // 距离矩阵
bool visited[MAX_N]; // 标记每个城市是否已经访问过
int N; // 城市数量
int minCost = INT_MAX; // 最小路径长度

// 回溯法寻找最短路径
void tsp(int currentCity, int count, int cost, int startCity) {
    if (count == N && dist[currentCity][startCity] > 0) { // 如果已经访问了所有城市，并且可以回到起点
        minCost = min(minCost, cost + dist[currentCity][startCity]); // 更新最小花费
        return;
    }

    // 访问剩下的城市
    for (int i = 0; i < N; ++i) {
        if (!visited[i] && dist[currentCity][i] > 0) { // 如果城市 i 未访问过且路径合法
            visited[i] = true; // 标记城市 i 已访问
            tsp(i, count + 1, cost + dist[currentCity][i], startCity); // 递归访问下一个城市
            visited[i] = false; // 回溯，标记城市 i 未访问
        }
    }
}

int main() {
    //cout << "请输入城市数量 N 和 开始城市: ";
    int n;
    cin >> N >> n;

    //cout << "请输入距离矩阵：" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }

    // 初始化访问标记数组
    for (int i = 0; i < N; ++i) {
        visited[i] = false;
    }

    // 从第 0 个城市开始旅行
    visited[n] = true; // 起点城市标记为已访问
    tsp(n, 1, 0, n); // 当前在第 0 城市，已经访问了 1 个城市，当前总成本为 0

    // 输出最小路径长度
    cout << minCost;

    return 0;
}
