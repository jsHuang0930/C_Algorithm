/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include<vector>
using namespace std; 

// class Solution {
// 暴力解法，提交超时
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
// 两遍hash
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;//建立hash表存放数组元素
        vector<int> b(2,-1);//存放结果
        for(int i=0;i<nums.size();i++)
            a.insert(map<int,int>::value_type(nums[i],i));
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0&&(a[target-nums[i]]!=i))
            //判断是否找到目标元素且目标元素不能是本身
            {
                b[0]=i;
                b[1]=a[target-nums[i]];
                break;
            }
        }
        return b;

    }
};
// @lc code=end

