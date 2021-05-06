/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
//方法三 三指针
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++)
        {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if (dp[i] == num2)
            {
                p2++;
            }
            if (dp[i] == num3)
            {
                p3++;
            }
            if (dp[i] == num5)
            {
                p5++;
            }
        }
        return dp[n];
    }
};

// @lc code=end
//方法一 暴力 超时
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n == 0)
            return false;
        while (n % 5 == 0)
            n /= 5;
        while (n % 3 == 0)
            n /= 3;
        while (n % 2 == 0)
            n /= 2;
        //n>>=1;
        if (n == 1)
            return true;
        else
            return false;
    }
    int nthUglyNumber(int n)
    {
        int count = 0, i = 1;
        while (count < n)
        {
            if (isUgly(i))
                count++;
            i++;
        }
        return i - 1;
    }
};

//方法二 map超时
class Solution
{
public:
    bool isUgly(map<int, int> &mp, int n)
    {
        if (n == 1 || n == 2 || n == 3 || n == 5)
        {
            mp[n] = n;
            return true;
        }

        if ((n % 2 == 0 && mp.count(n / 2)) || (n % 3 == 0 && mp.count(n / 3)) || (n % 5 == 0 && mp.count(n / 5)))
        {
            mp[n] = n;
            return true;
        }
        return false;
    }
    int nthUglyNumber(int n)
    {
        map<int, int> mp;
        int count = 0, i = 1;
        while (count < n)
        {
            if (isUgly(mp, i))
                count++;
            i++;
        }
        return i - 1;
    }
};
