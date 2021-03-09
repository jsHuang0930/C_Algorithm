/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// class Solution {//超时
// public:
//     int findShortestSubArray(vector<int>& nums) {
//         int maxcount = 0,res = 0;
//         if(nums.size()==1)
//             return 1;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int count = 1, length = 1;
//             for (int j = i+1; j < nums.size(); j++)
//             {
//                 if (nums[j]==nums[i])
//                 {
//                     count++;
//                     length = j - i + 1;
//                 }

//             }
//             if (count > maxcount)
//             {
//                 maxcount = count;
//                 res = length;
//             }
//             else if(count==maxcount){
//                 res = min(res,length);
//             }
//         }
//         return res;
//     }
// };
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> left, right, counter;
        //使用 left 和 right 分别保存了每个元素在数组中第一次出现的位置和最后一次出现的位置；使用 counter 保存每个元素出现的次数
        int degree = 0; //counter 的最大值
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!left.count(nums[i]))
                left[nums[i]] = i;
            right[nums[i]] = i;
            counter[nums[i]]++;
            degree = max(degree, counter[nums[i]]);
        }
        int res = nums.size();
        for (auto &kv : counter)
        {
            if (kv.second == degree)
            {
                res = min(res, right[kv.first] - left[kv.first] + 1);
            }
        }
        return res;
    }
};

// @lc code=end
