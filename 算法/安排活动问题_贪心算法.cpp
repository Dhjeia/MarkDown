// 贪心算法解决安排活动问题
/*
思路:
1.先接收有几个活动，循环录入活动开始和结束时间，每个活动用结构体存储
2.按照结束时间升序排序
3.如果下一个活动start大于结束时间，直接接入
*/

#include <algorithm>
#include <stdio.h>
using namespace std;

struct activity{
    int start;
    int end;
}activities[1001];

bool cmp(activity a, activity b){
    return  a.end <= b.end;
}

void countNumber(activity activities[], int n){
    int time = -1;  //目前活动结束时间
    int count = 0;  //活动个数

    for(int i = 1; i <= n; i++){
        if(activities[i].start >= time){
            count++;
            time = activities[i].end;
            //printf("录入的活动序号为%d\n",i);
        }
    }

    printf("%d\n",count);
}

int main(){
    int n;  //活动个数
    scanf("%d", &n);

    //录入
    activity activities[n];
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &activities[i].start, &activities[i].end);
        //printf("活动序号为%d(%d,%d)\n",i,activities[n].start,activities[n].end);
    }

    //按照结束时间升序排序
    sort(activities+1, activities+n, cmp);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &activities[i].start, &activities[i].end);
        //printf("活动序号为%d(%d,%d)\n",i,activities[i].start,activities[i].end);
    }

    //计算函数
    countNumber(activities,n);

    return 0;
}