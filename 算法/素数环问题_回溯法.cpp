#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX_N = 21; // 定义最大顶点数
int a[MAX_N]; // 存储每个顶点的值
bool used[MAX_N]; // 标记每个数字是否被使用
int n; // 顶点数

// 检查x是否为素数
bool isPrime(int x) {
    if (x <= 1) return false; // 1及以下的数不是素数
    if (x == 2) return true; // 2是素数
    for (int i = 2; i <= sqrt(x); ++i) { // 只需检查到sqrt(x)
        if (x % i == 0) return false; // 如果x能被i整除，则x不是素数
    }
    return true; // x是素数
}

// 使用递归进行回溯，生成素数环
void dfs(int pos) {
    if (pos == n && isPrime(a[n-1] + a[0])) { // 如果已经生成了n个数字，且首尾和为素数
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    // 尝试放置剩余的数字
    for (int i = 2; i <= n; ++i) { // 数字1已固定，从2开始尝试
        if (!used[i] && isPrime(a[pos-1] + i)) { // 确保数字未被使用，且与前一个数字和为素数
            a[pos] = i;
            used[i] = true;
            dfs(pos + 1); // 递归尝试下一个位置
            used[i] = false; // 回溯，撤销选择
        }
    }
}

int main() {
    cin >> n; // 输入需要找到的素数环的规格
    if (n % 2 == 1) { // 奇数不能构成素数环
        cout << "No Answer" << endl;
        return 0;
    }

    a[0] = 1; // 起始数字固定为1
    used[1] = true; // 标记1已经使用
    dfs(1); // 从第二个位置开始递归构造
    return 0;
}
