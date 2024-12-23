#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

const int MAX_CITIES = 10;  // 假设最多有10个城市

// 计算两城市之间的距离
int calculateDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void permute(int cities[], int left, int right, int n, int dist[MAX_CITIES][MAX_CITIES], int& minCost, int result[MAX_CITIES]) {
    // 递归结束条件
    if (left == right) {
        int cost = 0;
        // 计算当前排列的总路程
        for (int i = 0; i < n - 1; i++) {
            cost += dist[cities[i]][cities[i + 1]];
        }
        cost += dist[cities[n - 1]][cities[0]];  // 返回起点

        // 如果当前的总路程小于最小路程，则更新最小路程
        if (cost < minCost) {
            minCost = cost;
            for (int i = 0; i < n; i++) {
                result[i] = cities[i];
            }
        }
    } else {
        for (int i = left; i <= right; i++) {
            swap(cities[left], cities[i]);
            permute(cities, left + 1, right, n, dist, minCost, result);
            swap(cities[left], cities[i]);  // 回溯
        }
    }
}

int main() {
    int n;  // 城市数量
    cout << "请输入城市数量：";
    cin >> n;

    int coordinates[MAX_CITIES][2];  // 存储城市的坐标
    int dist[MAX_CITIES][MAX_CITIES];  // 存储城市间的距离

    cout << "请输入城市的坐标（x 和 y）：" << endl;
    for (int i = 0; i < n; i++) {
        cout << "城市 " << i + 1 << " 的坐标：";
        cin >> coordinates[i][0] >> coordinates[i][1];
    }

    // 计算距离矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                dist[i][j] = calculateDistance(coordinates[i][0], coordinates[i][1], coordinates[j][0], coordinates[j][1]);
            } else {
                dist[i][j] = 0;
            }
        }
    }

    // 输出城市距离矩阵
    cout << "\n城市距离矩阵：\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << "\t";
        }
        cout << endl;
    }

    int cities[MAX_CITIES];
    for (int i = 0; i < n; i++) {
        cities[i] = i;
    }

    int minCost = INT_MAX;
    int result[MAX_CITIES];

    permute(cities, 0, n - 1, n, dist, minCost, result);

    cout << "\n最短路线：";
    for (int i = 0; i < n; i++) {
        cout << result[i] + 1 << " ";  // 输出城市编号，从1开始
    }
    cout << "\n最小路程花费：" << minCost << endl;

    return 0;
}
