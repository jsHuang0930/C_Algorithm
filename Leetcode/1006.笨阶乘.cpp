/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int clumsy(int N)
    { //乘除直接算，加减先入栈
        stack<int> st;
        int count = 0;
        int res = 0;
        st.push(N);
        while (N - 1)
        {
            count++;
            if (count % 4 == 1)
                st.top() *= N - 1;
            else if (count % 4 == 2)
                st.top() /= N - 1;
            else if (count % 4 == 3)
                st.push(N - 1);
            else if (count % 4 == 0)
                st.push(1 - N);
            N--;
        }
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
// @lc code=end
