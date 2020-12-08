/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] 将数组拆分成斐波那契序列
 * 2020.12.8
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> splitIntoFibonacci(string S)
    {
        vector<int> list;
        backtrack(list, S, S.length(), 0, 0, 0);
        return list;
    }

    bool backtrack(vector<int> &list, string S, int length, int index, long long sum, int prev)
    {
        // 回溯+剪枝
        if (index == length)
        {
            // 当整个字符串拆分完毕时，如果列表中至少有 33 个数，则得到一个符合要求的斐波那契式序列，返回列表。
            // 如果没有找到符合要求的斐波那契式序列，则返回空列表。
            return list.size() >= 3;
        }
        long long curr = 0;
        for (int i = index; i < length; i++)
        {
            if (i > index && S[index] == '0')
            {
                break;
            }
            curr = curr * 10 + S[i] - '0';
            if (curr > INT_MAX)
            {
                break;
            }
            if (list.size() >= 2)
            {
                if (curr < sum)
                {
                    continue;
                }
                else if (curr > sum)
                {
                    break;
                }
            }
            list.push_back(curr);
            if (backtrack(list, S, length, i + 1, prev + curr, curr))
            {
                return true;
            }
            list.pop_back();
        }
        return false;
    }
};
// @lc code=end
