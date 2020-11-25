/*
 * @lc app=leetcode.cn id=1370 lang=cpp
 *
 * [1370] 上升下降字符串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string sortString(string s)
    {
        vector<int> num(26);
        for (char &ch : s)
        {
            num[ch - 'a']++;
        }

        string ret;
        while (ret.length() < s.length())
        { //ret.length() = s.length()时停止循环
            for (int i = 0; i < 26; i++)
            { //从小到大
                if (num[i])
                {
                    ret.push_back(i + 'a');
                    num[i]--; //第i个字符计数减一
                }
            }
            for (int i = 25; i >= 0; i--)
            { //从大到小
                if (num[i])
                {
                    ret.push_back(i + 'a');
                    num[i]--;
                }
            }
        }
        return ret;
    }
};

// @lc code=end
