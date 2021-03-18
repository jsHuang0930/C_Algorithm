/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray
{
public:
    vector<int> sums;

    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        //v.resize(int n,element)表示调整容器v的大小为n，扩容后的每个元素的值为element，默认为0
        //扩容为n+1，为了不对n=0的情况特殊处理
        sums.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            //sums[i]表示数组nums从下标0到下标i−1的前缀和
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j)
    {
        return sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
