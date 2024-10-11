/*
思路：
1.用二位矩阵A记录两两城市之间的距离，创建一个visited数组，标记这个城市是否被访问过
2.从起点开始，逐个比较跟这个城市相邻的所有城市，求的最小路径的城市前往
3.更行这个新城市已经被访问过，更新current城市为新城市
4.重复2、3，直到所有城市都被访问过，最后回到起点，求总距离
*/


#include <iostream>
#include <vector>
#include <climits> // 对于 INT_MAX

using namespace std;

// 贪婪算法解决TSP问题
void TSP(const vector<vector<int> >& A, int N, int start){
    vector<bool> visited(N, false); // 标记城市是否访问过
    int current = start; // 当前城市
    visited[current] = true; // 标记当前城市为已访问
    int totalDistance = 0; // 总距离

    cout << "路径: " << current + 1;

    //N个城市，要链接N-1段路
    for(int i = 0; i < N - 1; ++i){
        int next = -1;
        int minDistance = INT_MAX;

        // 寻找当前城市到未访问城市的最短距离
        for (int j = 0; j < N; ++j){
            //列举跟这个城市响铃的所有城市
            //如果这个城市没有访问过，并且到这个城市的距离比之前找到的距离短，就更新next和minDistance
            if (!visited[j] && A[current][j] < minDistance){
                minDistance = A[current][j];
                next = j;
            }
        }

        visited[next] = true; // 标记下一个城市为已访问
        totalDistance += minDistance; // 累加距离
        current = next; // 更新当前城市
        cout << " --> " << current + 1;
    }

    // 加上回到起点的距离
    int distanceBack = A[current][start];
    totalDistance += distanceBack;
    cout << " --> " << start + 1 << endl;

    cout << "最短路径长度：" << totalDistance << endl;
}

int main(){
    int N;
    cout << "输入城市个数:" << endl;
    cin >> N;

    vector<vector<int> > distances(N, vector<int>(N, 0));

    cout << "输入城市之间的距离(0表示城市间不通):" << endl;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> distances[i][j];
            if (distances[i][j] == 0 && i != j){
                distances[i][j] = INT_MAX; // 无连接的城市距离设置为无穷大
                distances[j][i] = INT_MAX;
            }
        }
    }

    // 从第一个城市开始旅行
    TSP(distances, N, 0);

    return 0;
}