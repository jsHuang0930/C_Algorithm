/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // if (nums.size() == 0)
        //     return false;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            //mp[nums[i]]++;
            if (++mp[nums[i]] == 2)
                return true;
        }
        return false;
    }
};
// @lc code=end
