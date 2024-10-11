//思路
// 0-1 背包问题
// 动态规划
//1. 定义状态：dp[i][j] 表示前i件物品恰好放入一个容量为j的背包可以获得的最大价值
//2. 转移方程：dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])
//3. 初始条件：dp[0][j] = 0, 0 <= j <= W
//4. 边界条件：dp[i][0] = 0, 0 <= i <= n

//dp[i][j]表示前i件物品恰好放入一个容量为j的背包可以获得的最大价值

#include <iostream>
using namespace std;

// 0-1 背包问题的动态规划实现
int knapsack(int c, int weights[], int values[], int n){
    int dp[n + 5][c + 5]; //定义二维dp数组

    // 初始化dp数组
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= c; j++){
            dp[i][j] = 0; // 初始条件
        }
    }

    //列表
    for (int i = 1; i <= n; i++){   //每一轮是前n个物品，在背包容量从0到c递增的价值判断
        for (int j = c; j >= 0; j--){   //如果j递增循环，会出现一个物品放入背包多次的问题
            if(j >= weights[i]){    //物品i放入背包
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]); 
                
                //if((i = 1) && (j >=4))   continue;
                printf("%d,%d--max(%d,%d+%d)\n",i,j,dp[i - 1][j],dp[i][j - weights[i]],values[i]);
                // 取两种情况的最大值，取放入物品i的价值和不放入物品i的最大值
                //dp[i][j - weights[i]]的意思是找到没有放入前一个物品的价值，剩余的价值再加上新物品的价值
                //value[i]是物品i的价值
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    //输出dp数组
    cout << "dp数组如下:" << endl;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= c; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // 返回能取得的最大价值
    return dp[n][c];
}

int main(){
    //接收
    int n, c;   //物品数量和背包容量
    cin >> n >> c;
    //weights[i]表示第i件物品的重量，values[i]表示第i件物品的价值
    int weights[n+1], values[n+1];
    for(int i = 1; i <= n; i++){
        weights[i] = 0;
        values[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        int weight, value;
        cin >> weight >> value;
        weights[i] = weight;
        values[i] = value;
    }

    int maxValue = knapsack(c, weights, values, n);
    cout << endl << "能够取得的最大价值为: " << maxValue << endl;
    

    return 0;
}
