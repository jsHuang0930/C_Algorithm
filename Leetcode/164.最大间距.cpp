/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int max_dif=0;
        vector<int>::iterator it;
        if (nums.size()<2)
        {
            return 0;
        }
        while (nums.size()>0)
        {
            it=nums.max_element();
            
        }
        
    }
};
// @lc code=end

