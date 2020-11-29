/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
bool cmp(int a,int b){
    return a>b;
}
class Solution {//简单题
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end(),cmp);
        for (int i = 0; i < A.size()-2; i++)
        {
            if(A[i+2]+A[i+1]>A[i])
                return A[i+2]+A[i+1]+A[i];
            
        }
        return 0;
    }
};
// @lc code=end

