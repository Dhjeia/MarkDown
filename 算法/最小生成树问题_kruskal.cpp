/*
思路：
1.用结构体edge录入图中的所有边
2.对边按照权重从小到大排序
3.开始连接图，从小边开始连接，
4.连接前判断两点的根结点不同才可连接，连接后更新其中一点的根结点=另外一点的根结点
5.直到所有边都被连接完毕，即连接的边数为n-1
*/


#include <stdio.h>
#include <algorithm>

using namespace std;

struct egde{
    int start, end, weight;
};

//