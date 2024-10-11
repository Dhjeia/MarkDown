//数塔最优路径
/*
思路：
1.二维数组arr[][]存储数组，dp[][]存储最短路径
2.接收数组金字塔，接收到最后一行到时候同时初始化dp数组最后一行最优路径
3.从最后一行开始往前遍历，对于每一行i，遍历j=0到i-1，
    对于每一个j，计算dp[i][j] = max(dp[i-1][j],dp[i-1][j+1]) + arr[i][j]
*/
# include <iostream>
# include <algorithm>
# include <stdio.h>
using namespace std;

void max_numberTower();

int main(){
    int T;   //T组测试
    scanf("%d", &T);
    while(T--){
        max_numberTower();
    }
    //system("pause");

    return 0;
}

void max_numberTower(){
    int arr[100][100] = {0};
    int dp[100][100] = {0};
    //初始化数组

    int n;  //每个数塔n行
    scanf("%d", &n);
    
    //接收数组
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d", &arr[i][j]);
            if(i == n){
                //录入到最后一行，顺便录入dp最后一行
                dp[i][j] = arr[i][j];
            }
        }
    }
    //计算最短路径
    for(int i = n - 1; i >= 1; i--){
        //从最低层开始计算
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + arr[i][j];

            //printf("[%d,%d]的是max(%d,%d) + %d\n",i,j,dp[i+1][j],dp[i+1][j+1],arr[i][j]);
        }
    }

    printf("%d\n", dp[1][1]);
}