#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;  // 定义一个很大的值表示不可达
const int MAXN = 20;  // 最大城市数量
int dist[MAXN][MAXN];  // 存储城市之间的距离
int dp[1 << MAXN][MAXN];  // 动态规划表，dp[mask][i] 表示当前状态为 mask，最后停留在城市 i 的最小花费
int n, startCity;  // 城市数量和起始城市

// TSP问题的动态规划+状态压缩解法
int tsp() {
    // 初始化 dp 表
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    
    // 从起始城市出发
    dp[1 << (startCity - 1)][startCity - 1] = 0;
    
    // 遍历所有的状态（每个状态的二进制位表示哪些城市已经被访问）
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (mask & (1 << u)) {  // 如果城市 u 已经在当前状态 mask 中被访问过
                for (int v = 0; v < n; v++) {
                    if (!(mask & (1 << v))) {  // 如果城市 v 还没有被访问
                        int nextMask = mask | (1 << v);  // 更新状态
                        dp[nextMask][v] = min(dp[nextMask][v], dp[mask][u] + dist[u][v]);  // 转移方程
                    }
                }
            }
        }
    }

    // 最后，从所有城市回到起始城市，计算最小值
    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i] + dist[i][startCity - 1]);
    }
    
    return ans;
}

int main() {
    cin >> n >> startCity;

    // 读取邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // 计算最小费用并输出
    cout << tsp() << endl;

    return 0;
}
