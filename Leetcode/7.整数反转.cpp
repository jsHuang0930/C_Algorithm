/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
# include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int tmp=x;//tmp存储每次去尾数后的结果
        long long res=0;
        while (tmp!=0)
        {
           res=(tmp%10)+res*10;
           //if (res>2147483648||res< -2147483647 )
           if(res>INT_MAX||res< INT_MIN)
           {
               return 0;
           }
           
           tmp/=10;
        }
        return res;
        
    }
};
// @lc code=end

