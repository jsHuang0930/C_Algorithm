/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 * 2020.12.12
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// class Solution {
//   public:
//     int wiggleMaxLength(vector<int> &nums) {
//         if (nums.size() < 2) { //数字个数少于2
//             return nums.size();
//         }
//         int dif = nums[1] - nums[0];
//         if (nums.size() == 2) { //数字个数等于2
//             if (dif == 0) {
//                 return 1;
//             } else {
//                 return 2;
//             }
//         }
//         int res;
//         int flag = 1;
//         if (dif == 0) { //开头两个数相等
//             res = 1;
//         } else { //开头两个数不相等
//             res = 2;
//         }

//         for (int i = 2; i < nums.size(); i++) {   //数字个数大于等于3
//             if ((nums[i] - nums[flag]) * dif < 0) //异号
//             {
//                 dif = nums[i] - nums[flag];
//                 flag = i;
//                 res++;

//             } else if ((nums[i] - nums[flag]) * dif > 0 ||
//                        nums[i] - nums[flag] == 0) //同号
//             {
//                 continue;
//             }
//             else if (dif==0)
//             {
//                 dif=nums[i] - nums[flag];
//             }
            
//         }
//         return res;
//     }
// };

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        vector<int> up(n), down(n);
        up[0] = down[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                up[i] = up[i - 1];
                down[i] = max(up[i - 1] + 1, down[i - 1]);
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
};

// @lc code=end
