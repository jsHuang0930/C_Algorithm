/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// class Solution {
// //常规遍历方法，重复运算太多，效率低
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> res={-1,-1};
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==target){
//                 count++;
//                 res[1]=i;
//             }
//         }
//         res[0]=res[1]-count+1;
//         return res;
//     }
// };

class Solution
{
public:
    int binarySearch(vector<int> &nums, int target, bool lower)
    {//二分查找 
     //lower为true，则查找第一个等于target的下标，否则查找第一个大于target的下标
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target))
            {
                right = mid - 1;
                ans = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int leftIdx = binarySearch(nums, target, true);//查找第一个等于target的下标
        int rightIdx = binarySearch(nums, target, false) - 1;//查找第一个大于target的下标
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
        {
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end
