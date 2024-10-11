#include <iostream>
using namespace std;

const int MAX_VERTICES = 100; // 定义最大顶点数
int c[MAX_VERTICES][MAX_VERTICES]; // 邻接矩阵，存储图的连接关系
int color[MAX_VERTICES];          // 记录每个顶点的颜色
int count;                        // 记录有效的着色方案数
int m, n;                         // m种颜色，n个顶点

// 检查第k个顶点的颜色是否满足条件
int Check(int k) {
    for (int i = 1; i <= k; i++) {
        if (c[k][i] == 1 && color[i] == color[k]) { // k与i之间相连并且i顶点的颜色与k顶点的颜色相同
            return 0;
        }
    }
    return 1;
}

// 图着色递归函数
void GraphColor(int step) {
    if (step == n + 1) { // 表示前面所有的顶点颜色都已经填完
        for (int i = 1; i <= n; i++) {
            //printf("%d ", color[i]); // 打印出一种着色方案
        }
        :: count++;
        //printf("\n");
        return;
    } else {
        for (int i = 1; i <= m; i++) {
            color[step] = i; // 首先将这个顶点颜色换为i
            if (Check(step) == 1) { // 检查是否符合条件
                GraphColor(step + 1); // 符合条件则走下一步
            }
            color[step] = 0; // 回溯，置为0
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m); // 输入顶点数和颜色数
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j]; // 输入邻接矩阵
        }
    }

    GraphColor(1); // 从第一个顶点开始着色
    printf("总的着色方案数:%d", :: count); // 输出总的着色方案数
    return 0;
}