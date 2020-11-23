/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{

public:
    static bool cmp(const vector<int> &u, const vector<int> &v)
    {
    /* void add(const A& a);  // 这样传入的就是引用，调用此函数时，就是直接使用a
    void add(A a);  // 这样传入的是对象的拷贝进去，需要构造这样的一个对象传递进去，效率没上面的高 */
        return u[1] < v[1]; //按右边界排序
    }
    int findMinArrowShots(vector<vector<int>> &points) //2维可变长数组 points = [[10,16],[2,8],[1,6],[7,12]]
    {                                                  
    /* 考虑所有气球中右边界位置最靠左的那一个，
    那么一定有一支箭的射出位置就是它的右边界（否则就没有箭可以将其引爆了）。
    当我们确定了一支箭之后，我们就可以将这支箭引爆的所有气球移除，
    并从剩下未被引爆的气球中，再选择右边界位置最靠左的那一个，
    确定下一支箭，直到所有的气球都被引爆。 */
        if (points.empty())
        {
            return 0;
        }

        sort(points.begin(), points.end(), cmp);
        int pos = points[0][1];
        int ans = 1;
        // for (const vector<int> &balloon : points)
        // {
        //     if (balloon[0] > pos)
        //     {
        //         pos = balloon[1];
        //         ++ans;
        //     }
        // }
        for (int i = 0; i < points.size(); i++)
        {
            if (points[i][0]>pos)//如果该点左端大于pos的右端
            {
                pos=points[i][1];//该点为新的pos
                ans++;
            }
            
        }
        
        return ans;
    }
};
// @lc code=end
