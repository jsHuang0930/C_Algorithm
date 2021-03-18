/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        vector<int> vec(INT_MAX, 0); //报错 out of memory
        if (nums.size() == 0)
        {
            return 1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 1)
            {
                vec[nums[i] - 1] = 1;
            }
            else
            {
                continue;
            }
        }
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == 0)
            {
                return i + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int firstMissingPositive(vector<int> &nums)
//     {
//         vector<int> vec(INT_MAX, 0); //报错 out of memory
//         if (nums.size() == 0)
//         {
//             return 1;
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] >= 1)
//             {
//                 vec[nums[i] - 1] = 1;
//             }
//             else
//             {
//                 continue;
//             }
//         }
//         for (int i = 0; i < vec.size(); i++)
//         {
//             if (vec[i] == 0)
//             {
//                 return i + 1;
//             }
//         }
//         return 0;
//     }
// };