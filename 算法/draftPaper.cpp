#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAX_N = 30;
vector<vector<int> > dist; // 距离矩阵
vector<vector<int> > dp; // 动态规划表，使用状态压缩
int N, S; // 城市数量和出发城市

// 动态规划+状态压缩解决TSP问题
int tsp(int mask, int pos) {
    if (mask == (1 << N) - 1) { // 如果已经访问了所有城市
        return dist[pos][S] > 0 ? dist[pos][S] : INT_MAX; // 返回到起点的距离，如果不可达则返回无穷大
    }
    if (dp[mask][pos] != -1) { // 如果该状态已经计算过，直接返回
        return dp[mask][pos];
    }

    int ans = INT_MAX; // 初始化最小值为无穷大
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0 && dist[pos][city] > 0) { // 如果城市还没有访问过并且路径合法
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city); // 递归计算新的路径
            ans = min(ans, newCost); // 更新最小值
        }
    }

    dp[mask][pos] = ans; // 记录最优解
    return ans;
}

int main() {
    // 读取城市数量和出发城市
    cin >> N >> S;
    S--; // 让出发城市的编号从0开始

    //边缘情况
    if(N == 1){
        cout << 0 << endl;
        return 0;
    }

    // 读取距离矩阵
    dist.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }

    // 初始化dp数组，-1表示未计算
    dp.resize(1 << N, vector<int>(N, -1));

    // 从出发城市开始，初始状态mask为1表示只访问了出发城市
    int result = tsp(1 << S, S);

    // 输出结果
    if (result == INT_MAX) {
        cout << "No solution" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
