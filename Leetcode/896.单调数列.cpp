/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
//两次遍历法（是否有两项递增或递减）
class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        return isIncrease(A) || isDecrease(A);
    }
    bool isIncrease(vector<int> &A)
    {
        int N = A.size();
        for (int i = 1; i < N; ++i)
        {
            if (A[i] < A[i - 1])
                return false;
        }
        return true;
    }

    bool isDecrease(vector<int> &A)
    {
        int N = A.size();
        for (int i = 1; i < N; ++i)
        {
            if (A[i] > A[i - 1])
                return false;
        }
        return true;
    }
};

//一次遍历
//使用 inc 标记数组是否单调上升的，如果有下降，则将其置为 false
//使用 dec 标记数组是否单调递减的，如果有上升，则将其置为 false
//如果数组是单调的，那么 inc 和 dec 会至少有一个一直保持 true
//如果 inc 和 dec 同时为 false，说明数列中既有递增的情况，也有递减的情况，所以数列就不是单调的
class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        bool inc = true;
        bool dec = true;
        for (int i = 1; i < A.size(); ++i)
        {
            if (A[i] < A[i - 1])
                inc = false;
            if (A[i] > A[i - 1])
                dec = false;
            if (!inc && !dec)
                return false;
        }
        return true;
    }
};

// @lc code=end

//错误方法 若前两项相等，，如1，1，0 则报错
class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        if (A.size() == 1) //数组长度为1
        {
            return true;
        }

        if (A[1] - A[0] >= 0) //起始两项递增
        {
            for (int i = 2; i < A.size(); i++)
            {
                if (A[i] - A[i - 1] < 0)
                {
                    return false;
                }
            }
        }
        if (A[1] - A[0] <= 0) //起始两项递减
        {
            for (int i = 2; i < A.size(); i++)
            {
                if (A[i] - A[i - 1] > 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};