/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{ //除第一行和第一列为1，其余网格的可达路径数为其左侧和上侧网格可达路径数之和
public:
    int uniquePaths(int m, int n)
    {
        //记住此处二维数组m*n初始化方式
        vector<vector<int>> counts(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                counts[i][j] = counts[i - 1][j] + counts[i][j - 1];
            }
        }
        return counts[m - 1][n - 1];
    }
};
// @lc code=end
