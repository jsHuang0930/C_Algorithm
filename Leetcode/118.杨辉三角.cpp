/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 * 2020.12.6
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        //vector<int> res[numRows];
        vector<vector<int>> res(numRows);
        //对于vector构建出来的二维数组没有进行空间的申请,比如有些返回类型为vector<vector<>>类型的函数，对于这个返回值vector表示的二维数组要先申请大小，否则使用下标访问就会报这类错误
        //reference binding to null pointer of type 'const value_type'
        // if (numRows == 0)
        //     return 0;
        if (numRows == 1)
        {
            res[0].push_back(1);
        }
        else if (numRows == 2)
        {
            res[0] = {1};
            res[1] = {1, 1};
        }
        else if (numRows >= 3)
        {
            res[0] = {1};
            res[1] = {1, 1};
            for (int i = 2; i < numRows; i++)
            {
                res[i].push_back(1);
                for (int j = 1; j < i; j++)
                {
                    res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
                res[i].push_back(1);
            }
        }
        return res;
    }
};
// @lc code=end
