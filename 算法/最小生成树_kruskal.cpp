/*
思路：
1.用结构体edge录入图中的所有边
2.对边按照权重从小到大排序
3.开始连接图，从小边开始连接，
4.连接前判断两点的根结点不同才可连接，连接后更新其中一点的根结点=另外一点的根结点
5.直到所有边都被连接完毕，即连接的边数为n-1
*/

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>  // 包含 INT_MAX 的定义
using namespace std;

struct Edge {
    long long a, b, value;
};


// 边的比较函数，用于排序
bool compareEdges(Edge e1, Edge e2) {
    return e1.value < e2.value;
}

int findParent(int connection[],int node) {
    if (connection[node] != node) {
        connection[node] = findParent(connection ,connection[node]); // 路径压缩
    }
    return connection[node];
}


void unionNodes(int connection[],int a, int b) {
    int parentA = findParent(connection,a);
    int parentB = findParent(connection,b);
    if (parentA != parentB) {
        connection[parentA] = parentB;
    }
}


void kruskal(Edge edges[], int edge, int connection[]) {
    int mst_weight = 0;  // 存储最小生成树的权值
    for (int i = 0; i < edge; i++) {
        // printf("%d次\n",i);
        // printf("%d 和 %d\n",edges[i].a,edges[i].b);
        if (findParent(connection,connection[edges[i].a]) != findParent(connection,connection[edges[i].b])) {
            unionNodes(connection,connection[edges[i].a], connection[edges[i].b]);
            mst_weight += edges[i].value;
            //cout << "边 (" << edges[i].a << ", " << edges[i].b << ") 加入最小生成树，权值：" << edges[i].value << endl;
        }
    }
    cout << mst_weight << endl;
}

int main() {
    int point, edge;
    int connection[100]; // 记录每个点的根结点
    Edge edges[100];
    scanf("%d%d",&point, &edge);

    //接收
    for (int i = 0; i < edge; i++) {
        int a, b, value;
        cin >> a >> b >> value;
        edges[i].a = a;
        edges[i].b = b;
        edges[i].value = value;
    
    }
    for (int i = 0; i < point; i++) {
        connection[i] = i;  //每个点的根结点初始化为自己
    }


    // 对边进行排序
    sort(edges, edges + edge, compareEdges);

    // printf("排序后结果\n");
    // for(int i = 0; i < edge; i++)
    //     printf("%d %d %d\n",edges[i].a,edges[i].b,edges[i].value); 

    // for (int i = 0; i < point; i++) {
    //     printf("%d节点\n",connection[i]);  //每个点的根结点初始化为自己
    // }

    // kruskal函数
    kruskal(edges, edge, connection);

    return 0;
}


/*
7 12
1 2 9
1 5 2
1 6 3
2 3 5
2 6 7
3 4 6
3 7 3
4 5 6
4 7 2
5 6 3
5 7 6
6 7 1
*/
