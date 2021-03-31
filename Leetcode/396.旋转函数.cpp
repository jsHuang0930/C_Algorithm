/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{ //超出时间限制
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int res = INT_MIN;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            int tmpres = 0;
            for (int j = 0; j < size; j++)
            {
                tmpres += nums[j] * ((j + i) % size);
            }
            res = max(res, tmpres);
        }
        return res;
    }
};

// @lc code=start
// 错位相减法
// （1）F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-2) * Bk[n-2] + (n-1) * Bk[n-1]
// （2）F(k+1) = 0 * Bk[n-1] + 1 * Bk[0] + 2 * Bk[2] + ... + (n-1) * Bk[n-2]
// （2）-（1）得：F(k+1) - F(k) = (Bk[0] + Bk[1] + ... + Bk[n-2]) - (n-1)*Bk[n-1]
// 可得：F(k+1) - F(k) = (Bk[0] + Bk[1] + ... + Bk[n-2] + Bk[n-1]) - n*Bk[n-1]
// 令S=Sum{Bk}
// 有：F(k+1) = F(k) + S - n * Bk[n-1]

class Solution
{
public:
    int maxRotateFunction(vector<int> &A)
    {
        long N = A.size();
        long S = 0;
        long t = 0;
        for (int i = 0; i < N; ++i)
        {
            S += A[i];
            t += i * A[i];
        }
        long res = t;
        for (int i = N - 1; i >= 0; --i)
        {
            // F(k+1) = F(k) + S - n * Bk[n-1]
            t += S - N * (long)A[i];
            res = max(res, t);
        }
        return res;
    }
};

// @lc code=end
