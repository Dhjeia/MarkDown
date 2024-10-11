/*
最长公共子序列（LCS）问题是指两个或多个序列中，找到最长的子序列，使得这两个或多个序列中所有元素都在这个子序列中出现，且顺序不变。

思路：
1.用s1,s2录入两个序列
2.用dp[i][j]表示s1的前i个字符和s2的前j个字符的最长公共子序列的长度
3.用S作为状态矩阵，输出最长子序列的回溯时候使用，1相等，2左移，3下移
*/

#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

void CommonOrder(string s1, string s2, int len1, int len2){
    //变量数组在定义的时候不能直接在后面={0}初始化
    int dp[len1+1][len2+1];     //长度矩阵
    int S[len1+1][len2+1];      //状态矩阵
    //初始化
    for(int i = 0; i <= len1; i++){
        for(int j = 0; j <= len2; j++)
        dp[i][j] = 0;
        //S[i][j] = 0;
    }
    //填充矩阵
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            //字母相同
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                //S[i][j] = 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    printf("%d", dp[len1][len2]);
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();

    CommonOrder(s1, s2, len1, len2);

    return 0;
}