/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                res[0] = nums[i];
                nums[i] = nums[i - 1] + 1;
                res[1] = nums[i];
                break;
            }
        }
        return res;
    }
};
// @lc code=end
