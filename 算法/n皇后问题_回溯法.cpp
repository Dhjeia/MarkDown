#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 15;
int queens[MAX_N];    // queens[i] 表示第 i 行皇后所在的列号
int solutions = 0;    // 解的数量
int N;                // 棋盘大小

// 检查 (row, col) 是否是安全的放置位置
bool isValid(int row, int col) {
    //逐行检查
    for (int i = 0; i < row; ++i) {
        // 检查同列和对角线冲突
        /*
        于两位皇后 (row1, col1) 和 (row2, col2) 来说，如果它们在同一对角线上，则满足条件：

        主对角线：row1 - col1 == row2 - col2 （行与列的差相同）
        副对角线：row1 + col1 == row2 + col2 （行与列的和相同）
        */
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

//放置皇后
void placeQueens(int row) {
    if (row == N) {  //如果已经放置了 N 个皇后，说明找到一个解
        ++solutions;
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (isValid(row, col)) {
            queens[row] = col;  // 将皇后放置在 (row, col)
            placeQueens(row + 1);  // 尝试下一行
            queens[row] = -1;  // 回溯，移除皇后
        }
    }
}

int main() {
    cout << "请输入棋盘大小 N: ";
    cin >> N;

    // 初始化皇后数组,queens[k]表示第k行中皇后的位置
    for (int i = 0; i < N; ++i) {
        queens[i] = -1;
    }

    placeQueens(0);  //从第 0 行开始放置皇后

    cout << "一共有 " << solutions << " 种解法。" << endl;

    return 0;
}
