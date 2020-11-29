/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{//Time Limit Exceeded
public:
    int reversePairs(vector<int> &nums)
    {
        vector<long long> numsdouble;
        int count = 0;
        if (nums.size() < 2)
            return 0;
        for (int i = 1; i < nums.size(); i++)
        {
            numsdouble.push_back((long long)nums[i] * 2);//强制类型转换
        }
        for (int j = 0; j < nums.size() - 1; j++)
        {
            for (int k = j; k < numsdouble.size(); k++)
            {
                if (nums[j] > numsdouble[k])
                {
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end
