// prim 算法求最小生成树 
// 思路：
// 1. 将录入的点存贮进二位矩阵中
// 2. 选择一个点作为起点，并将其与其他所有点的距离作为边权，存入最小堆中
// 3. 做一个数组 connection，录入所有已经被访问过的点，每次新链接的点，必须有一个点被访问过，另外一个点没有被访问过
// 4. 重复步骤2，直到所有点都被访问过，或者最小堆为空

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits> // 包含 INT_MAX 的定义

void prim(); // 函数声明

using namespace std;

int point, edge;
int map[100][100] = {0}; // 声明为0，方便后续使用
bool connection[100] = {0};

int main() {
cin >> point >> edge;

for (int i = 0; i < edge; i++) {
int a, b, value;
cin >> a >> b >> value;
map[a][b] = value;
map[b][a] = value;
map[i][i] = 1e4;
}
// 输出原始图
for (int i = 1; i <= point; i++) {
for (int j = 1; j <= point; j++) {
if (map[i][j] != INT16_MAX) {
cout << map[i][j] << " ";
} else {
cout << "0 ";
}
}
cout << endl;
}

// prim函数
prim();

return 0;
}

void prim() {
int total_value = 0; // 记录最小生成树权值
connection[1] = true; // 第一个点已经访问过
for (int i = 1; i < point; i++) { // 总共需要连接 point - 1 条边
int min_value = INT_MAX; // 存储当前最小边的权值
int A = -1, B = -1; // 用于存储要连接的边的两个点

// 寻找与已访问节点连接的最小权值的边
for (int j = 1; j <= point; j++) {
if (connection[j]) { // 从已访问的点寻找
for (int k = 1; k <= point; k++) {
if (!connection[k] && map[j][k] < min_value && map[j][k] != 0) { // 找未访问的点
min_value = map[j][k];
A = j;
B = k; // 记录边的两个端点
}
}
}
}
//printf("第%d次要链接的边权值是%d", i, min_value);
// 将找到的最小权值的边加入到最小生成树中
if (B != -1) {
connection[B] = true; // 标记新连接的点为已访问
total_value += min_value; // 更新总权值
//cout << total_value << endl;
}
}

// 输出最小生成树权值
cout << "最小生成树权值：" << total_value << endl;
}

/*
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
*/