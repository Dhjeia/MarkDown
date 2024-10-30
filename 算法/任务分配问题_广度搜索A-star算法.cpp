/*
使用更准确的启发式函数 f = g + h
1. g(i)：表示已经分配给当前工人的时间成本。
2. h(i)：表示剩余任务的每一行都选择最小的时间成本。
*/

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// 任务数量
const int TASKS = 3;
// 工人数量
const int WORKERS = 3;

// 任务成本矩阵
int cost[TASKS][WORKERS] = {
    {4, 2, 5}, // 任务0分配给不同工人的成本
    {3, 6, 1}, // 任务1分配给不同工人的成本
    {7, 5, 3}  // 任务2分配给不同工人的成本
};

// 全局变量
int minCost = numeric_limits<int>::max(); // 最小成本
int currentCost = 0; // 当前成本
int assignedTasks[WORKERS] = {0}; // 记录每个工人已分配的任务数量
int taskAssignment[TASKS]; // 记录每个任务分配给哪个工人

// 启发式函数：计算g(i) + h(i)
int heuristic(int taskIndex) {
    int remainingCost = 0; // 剩余任务的总成本初始化为0
    
    // 遍历所有未分配的任务
    for (int i = taskIndex; i < TASKS; i++) {
        int minTaskCost = numeric_limits<int>::max(); // 每个任务的最小成本初始化为最大值
        // 遍历可用工人，找到给当前任务分配的最小成本
        for (int j = 0; j < WORKERS; j++) {
            // 如果该工人未被分配任务，更新当前任务的最小成本
            if (assignedTasks[j] < 1) {
                minTaskCost = min(minTaskCost, cost[i][j]); // 更新当前任务的最小成本
            }
        }
        remainingCost += minTaskCost; // 累加剩余任务的最小成本
    }
    return remainingCost; // 返回未完成任务的估计成本
}

// A*算法实现任务分配
void aStar(int taskIndex) {
    // 如果所有任务都分配完成
    if (taskIndex == TASKS) {
        // 如果当前成本小于最小成本，则更新
        if (currentCost < minCost) {
            minCost = currentCost; // 更新最小成本
            // 记录任务分配情况
            for (int i = 0; i < TASKS; i++) {
                taskAssignment[i] = i; // 记录任务分配情况
            }
        }
        return; // 返回，终止当前递归
    }

    // 对于每个工人，尝试将当前任务分配给他
    for (int worker = 0; worker < WORKERS; worker++) {
        // 确保每个工人最多分配一个任务
        if (assignedTasks[worker] < 1) {
            assignedTasks[worker]++; // 标记该工人已分配任务
            currentCost += cost[taskIndex][worker]; // 更新当前成本
            taskAssignment[taskIndex] = worker; // 记录任务分配
            
            // 计算启发式估计
            int estimatedCost = currentCost + heuristic(taskIndex + 1); // 估计的总成本
            // 仅在估计的成本小于当前最小成本时继续搜索
            if (estimatedCost < minCost) { 
                aStar(taskIndex + 1); // 递归到下一个任务
            }
            
            // 回溯
            currentCost -= cost[taskIndex][worker]; // 撤销当前任务的分配
            assignedTasks[worker]--; // 取消工人任务的标记
        }
    }
}

int main() {
    aStar(0); // 从第一个任务开始
    cout << "完成任务时间成本最小值: " << minCost << endl; // 输出最小成本

    // 输出最终任务分配情况
    cout << "最终任务分配情况: ";
    for (int i = 0; i < TASKS; i++) {
        cout << "任务 " << i << " 分配给工人 " << taskAssignment[i] << "; ";
    }
    cout << endl;

    return 0;
}
