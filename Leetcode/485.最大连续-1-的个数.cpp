/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        int maxcount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) //nums[i]==0时
            {
                //maxcount = (maxcount > count) ? maxcount : count;
                maxcount = max(maxcount, count);
                count = 0;
            }
            else //nums[i]==1时
            {
                count++;
                if (i == nums.size() - 1) //数组以1结尾时
                    //maxcount = (maxcount > count) ? maxcount : count;
                    maxcount = max(maxcount, count);
            }
        }
        return maxcount;
    }
};
// @lc code=end
