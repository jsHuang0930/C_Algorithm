/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
//将整数转化为字符串
public:
    bool isPalindrome(int x) {
        string strx=to_string(x);
        int size=strx.size();
        for (int i = 0; i < size/2; i++)
        {
            if(strx[i]!=strx[size-1-i]){
                return false;
            }
        }
        return true;
        
    }
};
// @lc code=end

