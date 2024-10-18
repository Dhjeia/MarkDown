/*
输入与预处理：从标准输入中读取两个字符串 s 和 t，并初始化 DP 表 dp。dp[i][j] 表示使 s 的前 i 个字符和 t 的前 j 个字符相同所需的最小操作次数。
初始化：设置 dp[i][0] 和 dp[0][j]，分别表示当另一个字符串为空时，操作次数等于删除字符的数量。
动态规划填表：通过遍历 s 和 t，逐步填充 dp 数组。若字符相同，直接继承 dp[i-1][j-1]；否则，计算删除、替换等操作的最小次数。
输出结果：最终 dp[n][m] 就是将整个字符串 s 变为 t 所需的最少操作次数。
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int min_operations_to_match(const string& s, const string& t) {
    int n = s.size(), m = t.size();
    // dp 是一个大小为 (n+1) * (m+1) 的二维数组，其中所有元素初始化为 0。
    vector<vector<int> > dp(n+1, vector<int>(m+1));
    
    // 初始化边界情况
    for(int i=1; i<=n; i++) {
        dp[i][0] = i; // s非空，t为空，必须删除s的i个字符
    }
    for(int j=1; j<=m; j++) {
        dp[0][j] = j; // t非空，s为空，必须删除t的j个字符
    }

    // 动态规划填表
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // 如果当前字符相等，不需要操作
            } else {
                dp[i][j] = min(dp[i-1][j] + 1,      // 删除s[i-1]
                               min(dp[i][j-1] + 1,   // 删除t[j-1]
                                   dp[i-1][j-1] + 1)); // 替换操作
            }
        }
    }
    
    return dp[n][m]; // 返回将两个字符串完全匹配所需的最小操作次数
}

int main() {
    string s, t;
    // 输入两个字符串
    cin >> s >> t;
    // 输出最小操作次数
    cout << min_operations_to_match(s, t) << endl;
    return 0;
}
