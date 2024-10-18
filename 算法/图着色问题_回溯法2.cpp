#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_VERTICES = 7; // 定义最大顶点数（1 ≤ n ≤ 7）
int color[MAX_VERTICES + 1]; // 颜色数组，存储每个顶点的颜色，顶点编号从1开始
int min_colors; // 用于存储最小颜色数
bool adj[MAX_VERTICES + 1][MAX_VERTICES + 1]; // 邻接矩阵，存储图的边

// 判断顶点k的着色是否冲突
bool isSafe(int k, int n) {
    for (int i = 1; i <= n; i++) {
        // 如果有边相连，且颜色冲突，返回false
        if (adj[k][i] && color[i] == color[k]) {
            return false;
        }
    }
    return true;
}

// 使用回溯法进行图的着色
bool graphColoring(int k, int n, int m) {
    if (k == n + 1) { // 如果所有顶点都已经着色完毕
        return true;
    }

    // 尝试用m种颜色为第k个顶点着色
    for (int c = 1; c <= m; c++) {
        color[k] = c; // 为顶点k涂上颜色c
        if (isSafe(k, n)) { // 检查是否安全
            if (graphColoring(k + 1, n, m)) { // 递归为下一个顶点着色
                return true;
            }
        }
        color[k] = 0; // 回溯，重置颜色
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化邻接矩阵
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            adj[i][j] = false;
        }
    }

    // 输入图的边信息，填充邻接矩阵
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = true;
        adj[v][u] = true;
    }

    // 从1到n的颜色数尝试
    for (int m = 1; m <= n; m++) {
        fill(color, color + n + 1, 0); // 初始化颜色数组
        if (graphColoring(1, n, m)) { // 尝试用m种颜色进行着色
            cout << m << endl; // 找到最小颜色数
            break;
        }
    }

    return 0;
}
