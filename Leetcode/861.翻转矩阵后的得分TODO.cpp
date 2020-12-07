/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 * 2020.12.7
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& a) {
        //step1:翻转所有行，保证第一列全为1
        int m=a.size(),n=a[0].size();
        for (int i=0;i<m;i++)
        {
            if (a[i][0]!=1)
            {
                //翻转该行
                for (int j=0;j<n;j++)
                {
                    a[i][j]=!a[i][j];
                }
            }
        }
        //step2:从第二列开始，检查该列的1的数量是否大于等于0，如果不是，则翻转该列
        for (int j=1;j<n;j++)
        {
            int count=0;
            for (int i=0;i<m;i++)
            {
                if (a[i][j]) count++;
            }
            if (count<(m+1)/2)
            {
                for (int i=0;i<m;i++)
                {
                    a[i][j]=!a[i][j];
                }
            }
        }
        //step3:计算结果并返回
        int num=0;
        for(int j=0;j<n;j++)
        {
            int temp=pow(2,n-j-1);
            for (int i=0;i<m;i++)
            {
                num+=a[i][j]*temp;
            }
        }
        return num;
    }
};
// @lc code=end

