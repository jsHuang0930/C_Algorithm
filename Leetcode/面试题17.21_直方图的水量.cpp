#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  //方法一:对于每个位置，向左右找最高的木板；当前位置能放的水量是：左右两边最高木板的最低高度 - 当前高度
  int trap_1(vector<int> &height)
  {
    int res = 0, tmp = 0;
    int size = height.size();
    vector<int> lmax; //左边最高的柱子
    vector<int> rmax; //右边最高的柱子
    //错误写法！！！越界！！！
    // lmax[0] = 0;
    // rmax[0] = 0;
    lmax.push_back(0);
    rmax.push_back(0);
    for (int i = 1; i < size; i++)
    {
      //错误写法！！！越界！！！
      //lmax[i] = max(lmax[i - 1], height[i - 1]);
      //rmax[i] = max(rmax[i - 1], height[size - i]);
      lmax.push_back(max(lmax[i - 1], height[i - 1]));
      rmax.push_back(max(rmax[i - 1], height[size - i]));
    }
    for (int j = 0; j < size; j++)
    {
      tmp = min(lmax[j], rmax[size - j - 1]) - height[j]; //左右两边最高柱子的最小值 - 当前柱子的高度
      if (tmp > 0)
        //如果能蓄水
        res += tmp;
    }
    return res;
  }

  //方法二
  int trap_2(vector<int> &height)
  {
    int Sum = accumulate(height.begin(), height.end(), 0); // 得到柱子的体积
    int volume = 0;                                        // 总体积和高度初始化
    int high = 1;
    int size = size;
    int left = 0; // 双指针初始化
    int right = size - 1;
    while (left <= right)
    {
      while (left <= right && height[left] < high)
      {
        left++;
      }
      while (left <= right && height[right] < high)
      {
        right--;
      }
      volume += right - left + 1; // 每一层的容量都加起来
      high++;                     // 高度加一
    }
    return volume - Sum; // 总体积减去柱子体积，即雨水总量
  }
};
int main()
{
  Solution sol;
  int number;
  vector<int> height;
  while (1)
  {
    cin >> number;
    height.push_back(number); //每输入一个数字就把它添加到数组的最后
    if (cin.get() == '\n')    //如果是回车符则跳出循环
      break;
  }
  cout << sol.trap_1(height);
}
