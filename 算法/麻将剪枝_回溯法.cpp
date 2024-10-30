#include <iostream>
#include <unordered_map>
#include <array>

using namespace std;

// 使用哈希表来进行记忆化，减少重复计算
unordered_map<string, bool> memo;

// 将counts数组转换为字符串形式，用作哈希表的键
string countsToString(int counts[], int n) {
    string key = "";
    for (int i = 0; i < n; i++) {
        key += to_string(counts[i]) + ",";
    }
    return key;
}

// 判断是否能够组成四个面子和一个对子
bool canHu(int counts[], int n, int total);

// 判断是否能够组成四个面子
bool canMakeMianzi(int counts[], int n, int total) {
    if (total == 0) return true;  // 全部凑齐面子
    for (int i = 0; i < n; ++i) {
        // 检查刻子
        if (counts[i] >= 3) {
            counts[i] -= 3;
            if (canMakeMianzi(counts, n, total - 3)) {
                counts[i] += 3;  // 恢复
                return true;
            }
            counts[i] += 3;  // 恢复
        }
        // 检查顺子
        if (i + 2 < n && counts[i] > 0 && counts[i + 1] > 0 && counts[i + 2] > 0) {
            counts[i]--, counts[i + 1]--, counts[i + 2]--;
            if (canMakeMianzi(counts, n, total - 3)) {
                counts[i]++, counts[i + 1]++, counts[i + 2]++;
                return true;
            }
            counts[i]++, counts[i + 1]++, counts[i + 2]++;  // 恢复
        }
    }
    return false;
}

bool canHu(int counts[], int n, int total) {
    string key = countsToString(counts, n);
    
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    // 如果总数为0，表示已经完全消耗完牌，返回true
    if (total == 0) return true;
    
    // 先寻找对子
    for (int i = 0; i < n; ++i) {
        if (counts[i] >= 2) {
            counts[i] -= 2;
            if (canMakeMianzi(counts, n, total - 2)) {
                memo[key] = true;
                counts[i] += 2;  // 恢复现场
                return true;
            }
            counts[i] += 2;  // 恢复现场
        }
    }
    
    memo[key] = false;
    return false;
}

int main() {
    int n;
    cin >> n;

    // 如果n太小，不可能组成14张牌
    if (n * 4 < 14) {
        cout << 0 << endl;
        return 0;
    }
    
    int counts[100] = {4};  // 每种牌有4张，假设最多有100种牌，初始化为4
    int total = 14;  // 总共14张牌
    
    int res = 0;
    
    // 使用深度优先搜索与记忆化的方式查找所有可能的胡牌方式
    if (canHu(counts, n, total)) {
        res++;
    }
    
    cout << res << endl;
    
    return 0;
}
