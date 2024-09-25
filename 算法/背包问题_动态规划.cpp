//思路
// 0-1 背包问题
// 动态规划
//1. 定义状态：dp[i][j] 表示前i件物品恰好放入一个容量为j的背包可以获得的最大价值
//2. 转移方程：dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])
//3. 初始条件：dp[0][j] = 0, 0 <= j <= W
//4. 边界条件：dp[i][0] = 0, 0 <= i <= n

#include <iostream>
using namespace std;

// 0-1 背包问题的动态规划实现
int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1]; //定义二维dp数组

    // 初始化dp数组
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = 0; // 初始条件
        }
    }

    // 动态规划过程
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            //物品i不放入背包
            if (j < weights[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {    //物品i放入背包
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    //输出dp数组
    cout << "dp数组如下:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // 返回能取得的最大价值
    return dp[n][W];
}

int main() {
    //背包容量为10
    int W = 10;
    //物品的重量
    int weights[] = {2, 3, 4, 5};
    //物品的价值
    int values[] = {3, 4, 5, 6};
    int n = sizeof(weights) / sizeof(weights[0]); // 物品数量

    int maxValue = knapsack(W, weights, values, n);
    cout << endl << "能够取得的最大价值为: " << maxValue << endl;
    

    return 0;
}