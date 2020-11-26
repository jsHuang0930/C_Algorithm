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
    int maximumGap(vector<int> &nums) {
        int max_dif = 0; //最大差值
        vector<int>::iterator it;
        if (nums.size() < 2) { //数组元素个数小于 2，因此返回 0
            return 0;
        }
        it = min_element(nums.begin(), nums.end()); // tmp为剩余nums中的最小值
        int tmp = *it;
        nums.erase(it);
        while (nums.size() > 0) {
            it = min_element(nums.begin(), nums.end());
            if (max_dif < *it - tmp) {
                max_dif = *it - tmp;
            }
            tmp = *it;
            nums.erase(it);
        }
        return max_dif;
    }
};
// @lc code=end
