/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int l = 0, r = 0, res = 0;
        for (int i = 0; i < timeSeries.size(); i++)
        {
            l = max(timeSeries[i], r);
            r = timeSeries[i] + duration;
            res += r - l; //左右区间之差
        }
        return res;
    }
};
// @lc code=end
