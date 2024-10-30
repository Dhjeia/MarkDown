分支界限法（Branch and Bound）是一种解决旅行商问题（TSP）的优化算法。以下是基本思路及示例：

### 算法思路

1. **节点表示**：每个节点代表一个城市的访问状态。
2. **界限计算**：通过估算当前路径的最小费用来剪枝不必要的搜索。
3. **分支生成**：从当前节点扩展出可以到达的下一个城市，形成新节点。

### 示例

假设我们有四个城市，城市间的距离如下：

```
    A   B   C   D
A   0   10  15  20
B   10  0   35  25
C   15  35  0   30
D   20  25  30  0
```

### 代码示例

```python
import numpy as np

class TSP:
    def __init__(self, dist_matrix):
        self.dist_matrix = dist_matrix
        self.n = len(dist_matrix)
        self.final_res = float('inf')
        self.final_path = []

    def tsp(self):
        # Start from the first city
        visited = [False] * self.n
        visited[0] = True
        self._tsp_util(0, 1, 0, visited, [0])

    def _tsp_util(self, curr_pos, count, cost, visited, path):
        if count == self.n and self.dist_matrix[curr_pos][0]:
            total_cost = cost + self.dist_matrix[curr_pos][0]
            if total_cost < self.final_res:
                self.final_res = total_cost
                self.final_path = path + [0]
            return
        
        for i in range(self.n):
            if not visited[i] and self.dist_matrix[curr_pos][i]:
                visited[i] = True
                self._tsp_util(i, count + 1, cost + self.dist_matrix[curr_pos][i], visited, path + [i])
                visited[i] = False

# 距离矩阵
distance_matrix = np.array([[0, 10, 15, 20],
                             [10, 0, 35, 25],
                             [15, 35, 0, 30],
                             [20, 25, 30, 0]])

tsp_solver = TSP(distance_matrix)
tsp_solver.tsp()

print(f"最小路径：{tsp_solver.final_path}，总费用：{tsp_solver.final_res}")
```

### 运行过程说明

1. **初始状态**：从城市A出发，标记为已访问。
2. **生成子节点**：探索城市B、C、D，计算到达每个城市的费用。
3. **剪枝**：如果某条路径的费用超过当前已知最小值，则停止探索。
4. **最终结果**：找到访问所有城市并返回起点的最小费用路径。

以上就是分支界限法在TSP问题中的实现和示例。