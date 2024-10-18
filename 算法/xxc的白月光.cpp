
/*
在一个 N×N 的棋盘上放置 K 个人，要求每个人周围的 8 个格子（上下左右和四个对角）都不能有其他人。问有多少种符合条件的放置方案。
*/

/*
1. 读取输入 N 和 K，初始化棋盘为 N×N。
2. 用 dx, dy 数组表示 8 个方向偏移量。
3. isValid 检查 (x, y) 位置周围是否有人。
4. placePerson 用回溯法放人，递归检查方案。
5. 输出方案数
*/

#include<iostream>
#include<vector>
using namespace std;

int N, K; // N 是棋盘大小，K 是需要放置的人的数量
int ans = 0; // 记录符合条件的方案数
vector<vector<int> > board; // 棋盘

// 用于表示八个方向（上下左右 + 四个对角线）
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 判断在 (x, y) 放人是否合法，即 (x, y) 的 8 个方向上没有人
bool isValid(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] == 1) {
            return false; // 若在 8 个方向上有其他人，返回不合法
        }
    }
    return true;
}

// 使用回溯法来放置人
void placePerson(int placed, int pos) {
    // 剪枝：如果剩余空位不足以放置剩余的人，提前结束递归
    if (N * N - pos < K - placed) return;
    
    if (placed == K) {
        ans++; // 若成功放置了 K 个人，记录一种方案
        return;
    }
    
    // 从 pos 位置开始，尝试放置剩下的人
    for (int i = pos; i < N * N; i++) {
        int x = i / N; // 行号
        int y = i % N; // 列号
        if (board[x][y] == 0 && isValid(x, y)) { // 当前格子为空且合法
            board[x][y] = 1; // 放置一个人
            placePerson(placed + 1, i + 1); // 继续放置下一个人
            board[x][y] = 0; // 回溯，撤销当前放置
        }
    }
}

int main() {
    cin >> N >> K;
    board = vector<vector<int> >(N, vector<int>(N, 0)); // 初始化棋盘
    placePerson(0, 0); // 从放置 0 个人开始，位置从 0 号格子开始
    cout << ans << endl; // 输出结果
    return 0;
}
