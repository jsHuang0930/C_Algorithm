/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{//使用哈希表（我的code）
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        map<int, int> E, F;
        int count = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A.size(); j++)
            {
                E[A[i] + B[j]]++; //可见map初始键值为0
            }
        }
        map<int, int>::iterator it;
        int tmp;
        for (int k = 0; k < C.size(); k++)
        {
            for (int l = 0; l < C.size(); l++)
            {
                it = E.find(-(C[k] + D[l]));
                count+=it->second;
            }
        }
        return count;
    }
};

// class Solution 
//{//答案的code
// public:
//     int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//         unordered_map<int, int> countAB;
//         for (int u: A) {
//             for (int v: B) {
//                 ++countAB[u + v];
//             }
//         }
//         int ans = 0;
//         for (int u: C) {
//             for (int v: D) {
//                 if (countAB.count(-u - v)) {
//                     ans += countAB[-u - v];
//                 }
//             }
//         }
//         return ans;
//     }
// };

// @lc code=end
