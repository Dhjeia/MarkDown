#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

int t = 0;

vector<vector<int> > board;

void ChessBoard(int tr, int tc, int dr, int dc, int size)
// tr和tc是棋盘左上角的下标，dr和dc是特殊方格的下标，
// size是棋盘的大小，t已初始化为0
{
    if (size == 1) return;  // 棋盘只有一个方格且是特殊方格
    t++;  // L型骨牌号
    int t1 = t;
    int s = size / 2;  // 划分棋盘
    
    // 覆盖左上角子棋盘
    if (dr < tr + s && dc < tc + s)   // 特殊方格在左上角子棋盘中
        ChessBoard(tr, tc, dr, dc, s); // 递归处理子棋盘
    else { // 用 t 号L型骨牌覆盖右下角，再递归处理子棋盘
        board[tr + s - 1][tc + s - 1] = t1;
        ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }
    
    // 覆盖右上角子棋盘
    if (dr < tr + s && dc >= tc + s)    // 特殊方格在右上角子棋盘中
        ChessBoard(tr, tc + s, dr, dc, s); // 递归处理子棋盘
    else { // 用 t 号L型骨牌覆盖左下角，再递归处理子棋盘
        board[tr + s - 1][tc + s] = t1;
        ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    // 覆盖左下角子棋盘
    if (dr >= tr + s && dc < tc + s)   // 特殊方格在左下角子棋盘中
        ChessBoard(tr + s, tc, dr, dc, s); // 递归处理子棋盘
    else { // 用 t 号L型骨牌覆盖右上角，再递归处理子棋盘
        board[tr + s][tc + s - 1] = t1;
        ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }

    // 覆盖右下角子棋盘
    if (dr >= tr + s && dc >= tc + s)  // 特殊方格在右下角子棋盘中
        ChessBoard(tr + s, tc + s, dr, dc, s); // 递归处理子棋盘
    else { // 用 t 号L型骨牌覆盖左上角，再递归处理子棋盘
        board[tr + s][tc + s] = t1;
        ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}

int main() {
    int n; // 棋盘大小
    cin >> n;

    board.resize(n, vector<int>(n, 0));

    int dr, dc; // 特殊方格的位置
    cin >> dr >> dc;

    ChessBoard(0, 0, dr, dc, n);

    for (const auto &row : board) {
        for (int cell : row) {
            cout << left << setw(5) << cell; // 设置输出宽度为5，靠左对齐
        }
        //cout << endl;
    }

    return 0;
}
//3    3    4    4    8    8    9    9    
//3    2    0    4    8    7    7    9    
//5    2    2    6    10   10   7    11   
//5    5    6    6    1    10   11   11   
//13   13   14   1    1    18   19   19   
//13   12   14   14   18   18   17   19   
//15   12   12   16   20   17   17   21   
//15   15   16   16   20   20   21   21   