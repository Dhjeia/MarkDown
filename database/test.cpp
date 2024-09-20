#include <iostream>
using namespace std;

// 快速幂计算
long long fast_power(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod;  //先对 base 取模，避免大数溢出

    while (exponent > 0) {
        if (exponent % 2 == 1) {  //如果 exponent 是奇数
            result = (result * base) % mod; //计算时直接对 mod 取模
        }
        base = (base * base) % mod;  //平方 base，并对 mod 取模
        exponent /= 2;  //指数右移
    }
    return result;
}

int main() {
    // 一次性输入三个数字
    long long a, n, m;
    cin >> a >> n >> m;

    // 检查 m 是否为 0，避免除以 0
    if (m <= 0) {
        throw invalid_argument("模数 m 不能小于或等于 0");
    }

    // 使用快速幂算法计算 a^n mod m
    long long result = fast_power(a, n, m);
    cout << result << endl;

    return 0;
}
