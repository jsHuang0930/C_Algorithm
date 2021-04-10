/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 1 || nums[0] < nums[nums.size() - 1])
        {
            return nums[0];
        }
        else
        {
            for (int i = 0; i < nums.size() - 2; i++)
            {
                if (nums[i + 1] < nums[i])
                    return nums[i + 1];
            }
        }
        return 0;
    }
};
// @lc code=end
