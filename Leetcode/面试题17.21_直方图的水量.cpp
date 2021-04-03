#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int trap(vector<int> &height)
  {
    int Sum = accumulate(height.begin(), height.end(), 0); // 得到柱子的体积
    int volume = 0;                                        // 总体积和高度初始化
    int high = 1;
    int size = height.size();
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
  cout << sol.trap(height);
}
