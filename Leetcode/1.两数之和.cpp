/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include<vector>
using namespace std; 

// class Solution {
// 提交超时
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int i, j;
//         for(i=0;i<nums.size()-1;i++){
//             for(j=i+1;j<nums.size();j++){
//                 if(nums[j]==target-nums[i]){
//                     return {i,j};
//                 }
//             }
//         }
//         return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        for(i=0;i<nums.size()-1;i++){
            for(j=i+1;j<nums.size();j++){
                if(nums[j]==target-nums[i]){
                    return {i,j};
                }
            }
        }
        return {};
    }
};
// @lc code=end

