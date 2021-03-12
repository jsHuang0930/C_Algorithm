/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{ //与题[448]方法一致
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[(nums[i] - 1) % nums.size()] > nums.size()) //如果以nums[i]为索引指向的值大于nums.size,则说明该值被访问过
            {
                //nums[i]对nums.size取模 即为重复的值（因为之前可能被访问过，所以需要取模）
                res.push_back((nums[i] - 1) % nums.size() + 1); //为什么要这样写，而不是像下面的直接取模？因为若重复数字等于nums.size如8，那么（8+8）%8 结果为0，而我们要的是8
                //res.push_back(nums[i] % nums.size());
                continue;
            }
            nums[(nums[i] - 1) % nums.size()] += nums.size();
        }
        return res;
    }
};
// @lc code=end
