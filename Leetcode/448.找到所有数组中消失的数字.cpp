/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            //nums[nums[i] % nums.size() - 1] += nums.size();//当nums[i]=nums.size时，指向的数组索引就变成-1，会发生越界，故修改如下
            nums[(nums[i] - 1) % nums.size()] += nums.size(); //将以 nums[i]的值减一 为的下标的nums值加一个nums.size，循环一遍后nums值小于nums.size，说明没有找到这个值的下标，那么这个值的下标加一就是丢失的数
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= nums.size())
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
// @lc code=end
