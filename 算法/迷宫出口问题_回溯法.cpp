/*
小明某天不小心进入了一个迷宫（如上图所示）。请帮他判断能否出走出迷宫，如果可能，则输出一共有多少种不同的走法（对于某种特定的走法，必须保证不能多次走到同一个位置）。如果不能走到出口，则输出impossible。每次走只能是上、下、左、右4个方向之一。

输入格式:
测试数据有多组，处理到文件尾。每组测试数据首先输入2个整数n,m(0<n，m≤100)，代表迷宫的高和宽，然后n行，每行m个字符，各字符的含义如下：
S 代表小明现在所在的位置；T 代表迷宫的出口；# 代表墙，不能走；. 代表路，可以走。
*/


//---------------------------------------------------------

/*
思路
1.读取maze迷宫和各项数据，不需要录入.和#,在递归函数中判断是否为这两个符号即可
2.递归函数
    如果已经到达T，方法数字+1，回溯
    用方向数组判断四个当前点的四个方向是否可以走：
        1.可以走：标记当前点已经访问过，更像当前点位置，对下一个点使用递归函数
        2.不可以走：回溯，当前点标记为没有访问过
3.输出
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m;  // 迷宫的高和宽
vector<vector<char> > maze;  // 存储迷宫
vector<vector<bool> > visited;  // 标记是否访问过
int startX, startY, endX, endY;  // 起点和终点的坐标
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 4个方向：右、下、左、上
int pathCount;  // 记录不同走法的数量

// DFS递归函数
void dfs(int x, int y) {
    // 如果已经到达终点T，记录一种走法
    if (x == endX && y == endY) {
        pathCount++;
        return;
    }

    // 遍历4个方向
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        // 检查新位置是否合法
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY] != '#' && !visited[newX][newY]) {
            visited[newX][newY] = true;  // 标记新位置为已访问
            dfs(newX, newY);  // 递归探索新位置
            visited[newX][newY] = false;  // 回溯，恢复状态
        }
    }
}

int main() {
    // 持续处理多组测试数据，直到文件结束
    while (cin >> n >> m) {
        maze.resize(n, vector<char>(m));
        visited.resize(n, vector<bool>(m, false));
        startX = startY = endX = endY = -1;
        pathCount = 0;

        // 读取迷宫
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> maze[i][j];
                if (maze[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (maze[i][j] == 'T') {
                    endX = i;
                    endY = j;
                }
            }
        }

        // 如果起点或终点没有找到，直接输出impossible
        if (startX == -1 || endX == -1) {
            cout << "impossible" << endl;
            continue;
        }

        // 从起点开始DFS
        visited[startX][startY] = true;  // 标记起点已访问
        dfs(startX, startY);

        // 输出结果
        if (pathCount > 0) {
            cout << pathCount << endl;
        } else {
            cout << "impossible" << endl;
        }
    }

    return 0;
}
