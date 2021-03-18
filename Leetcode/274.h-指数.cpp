/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */
#include <bits\stdc++.h>
using namespace std;

// @lc code=start

//个人觉得这题有问题
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        if (citations[citations.size() - 1] == 0) //全为0次引用
            return 0;
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations.size() - i <= citations[i])
                return citations.size() - i;
        }
        return 0;
    }
};
// @lc code=end
