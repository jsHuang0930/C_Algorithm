/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        map<int, bool> mp; // map会以键从小到大自动排序
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] = true;
        if (mp.size() < 3) //第三大的数不存在
        {
            return mp.rbegin()->first;
        }

        int count = -1;
        for (map<int, bool>::iterator it = mp.end(); it != mp.begin(); it--)
        { //第三大的数存在且不为最小的那个

            count++;
            if (count == 3)
                return it->first;
        }
        return mp.begin()->first; //最小的那个为第三大的数
    }
};
// @lc code=end
