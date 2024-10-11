#include <iostream>
#include <cmath>
using namespace std;

const int MAX_N = 10; // 定义最大顶点数
int a[MAX_N]; // 存储每个顶点的值
int n = MAX_N; // 顶点数

// 检查x是否为素数
int isPrime(int x) {
    if (x <= 1) return 0; // 1及以下的数不是素数
    if (x == 2) return 1; // 2是素数
    for (int i = 2; i <= sqrt(x); ++i) { // 只需检查到sqrt(x)
        if (x % i == 0) return 0; // 如果x能被i整除，则x不是素数
    }
    return 1; // x是素数
}

// 检查当前值是否满足素数环的条件
int check(int pos) {
    for (int i = 0; i < pos; ++i) { // 检查是否有重复的值
        if (a[i] == a[pos]) return 0;
    }
    int flag = isPrime(a[pos] + a[pos - 1]); // 检查相邻两个顶点的值之和是否为素数
    if (flag && pos == n - 1) { // 如果是最后一个顶点，还需要检查它与第一个顶点的值之和是否为素数
        flag = isPrime(a[pos] + a[0]);
    }
    return flag; // 返回检查结果
}

int main() {
    for (int i = 0; i < n; ++i) a[i] = 0; // 初始化数组
    a[0] = 1; // 第一个顶点的值设为1
    int k = 1; // 当前正在尝试的顶点位置
    int n1; // 用户输入的环的数量
    cout << "输入需要找到的素数环的数量";
    cin >> n1; // 输入需要找到的素数环的数量

    while (n1--) { // 对于每个环
        while (k >= 0) { // 当k小于0时，表示需要回溯
            a[k]++; // 尝试下一个可能的值
            while (a[k] <= n) { // 当前值在1到n之间
                if (check(k)) { // 如果当前值满足条件
                    break; // 停止增加a[k]
                } else {
                    a[k]++; // 否则，尝试下一个值
                }
            }
            if (a[k] <= n && k == n - 1) { // 如果找到了一个解
                for (int i = 0; i < n; ++i) { // 打印解
                    cout << a[i] << " ";
                }
                cout << endl;
                k = 0; // 重置k，开始寻找下一个解
            } else if (a[k] <= n && k < n - 1) { // 如果当前顶点不是最后一个，且找到了合适的值
                k++; // 移动到下一个顶点
            } else { // 需要回溯
                a[k--] = 0; // 将当前顶点的值重置为0，并移动到前一个顶点
            }
        }
    }
}