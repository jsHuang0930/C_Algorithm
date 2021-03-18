/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{ //方法一：排序，最大乘积不是最小两项乘最大项，就是最大三项的乘积
public:
    int maximumProduct(vector<int> &nums)
    {
        int res;
        if (nums.size() == 3)
        {
            res = nums[0] * nums[1] * nums[2];
            return res;
        }
        sort(nums.begin(), nums.end());
        res = max(nums[0] * nums[1] * *(nums.end() - 1), *(nums.end() - 1) * *(nums.end() - 2) * *(nums.end() - 3)); //注意这里的end()是尾元素的下一个地址
        return res;
    }
};
// @lc code=end

class Solution
{ //方法二：线性扫描，只要求出数组中最大的三个数以及最小的两个数
public:
    int maximumProduct(vector<int> &nums)
    {
        // 最小的和第二小的
        int min1 = INT_MAX, min2 = INT_MAX;
        // 最大的、第二大的和第三大的
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (int x : nums)
        {
            if (x < min1)
            {
                min2 = min1;
                min1 = x;
            }
            else if (x < min2)
            {
                min2 = x;
            }

            if (x > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x > max2)
            {
                max3 = max2;
                max2 = x;
            }
            else if (x > max3)
            {
                max3 = x;
            }
        }

        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};