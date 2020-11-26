# LeetCode题解

## 222.完全二叉树的节点个数

### 对位运算的解释

```C
          1            h = 0
         / \
        2   3          h = 1
       / \  /
      4  5 6           h = 2
```

- 现在这个树中的值都是节点的编号，最底下的一层的编号是 [2^h ，2^h - 1]，现在h = 2，也就是4, 5, 6, 7。4, 5, 6, 7对应二进制分别为 100 101 110 111 不看最左边的1，从第二位开始，0表示向左，1表示向右，正好可以表示这个节点相对于根节点的位置。比如4的 00 就表示从根节点 向左 再向左。6的 10 就表示从根节点 向右 再向左

- 那么想访问最后一层的节点就可以从节点的编号的二进制入手。从第二位开始的二进制位表示了最后一层的节点相对于根节点的位置。那么就需要一个bits = 2^(h - 1) 这里就是2，对应二进制为010。这样就可以从第二位开始判断。比如看5这个节点存不存在，先通过位运算找到编号为5的节点相对于根节点的位置。010 & 101 发现第二位是0，说明从根节点开始，第一步向左走。之后将bit右移一位，变成001。001 & 101 发现第三位是1，那么第二步向右走。最后bit为0，说明已经找到编号为5的这个节点相对于根节点的位置，看这个节点是不是空，不是说明存在，exist返回真，编号为5的节点存在，说明总节点数量一定大于等于5。所以二分那里low = mid。

- 再比如看7存不存在，010 & 111 第二位为1，第一部从根节点向右；001 & 111 第三位也为1，第二步继续向右。然后判断当前节点是不是null，发现是null，exist返回假。编号为7的节点不存在，说明总节点数量一定小于7。所以high = mid - 1。

``` cpp
class Solution {
//二分查找+位运算
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        TreeNode* node = root;
        while (node->left != nullptr) {
            level++;
            node = node->left;
        }
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    bool exists(TreeNode* root, int level, int k) {
        int bits = 1 << (level - 1);
        TreeNode* node = root;
        while (node != nullptr && bits > 0) {
            if (!(bits & k)) {
                node = node->left;
            } else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
};
```  

## 1370.完全二叉树的节点个数

- 直接创建一个大小为 2626 的桶，记录每种字符的数量。每次提取最长的上升或下降字符串时，我们直接顺序或逆序遍历这个桶。
- 具体地，在遍历桶的过程中，如果当前桶的计数值不为零，那么将当前桶对应的字符加入到答案中，并将当前桶的计数值减一即可。我们重复这一过程，直到答案字符串的长度与传入的字符串的长度相等。

- string的push_back方法

``` c
    string str;
    str.push_back
```

## 7.整数反转

- 取整数各位数 先取模10，得尾数；再除10去尾数

  1. 将12345 % 10 得到5，之后将12345 / 10
  2. 将1234 % 10 得到4，再将1234 / 10
  3. 将123 % 10 得到3，再将123 / 10
  4. 将12 % 10 得到2，再将12 / 10
  5. 将1 % 10 得到1，再将1 / 10

- 有了取模和除法操作，对于像12300这样的数字，也可以完美的解决掉了。
- 这么看起来，一个循环就搞定了，循环的判断条件是x>0。但这样不对，因为忽略了负数，循环的判断条件应该是while(x!=0)，无论正数还是负数，按照上面不断的/10这样的操作，最后都会变成0，所以判断终止条件就是!=0。
- 看起来这道题就这么解决了，但请注意，题目上还有这么一句
  >假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。
- 也就是说我们不能用long存储最终结果，而且有些数字可能是合法范围内的数字，但是反转过来就超过范围了。假设有1147483649这个数字，它是小于最大的32位整数2147483647的，但是将这个数字反转过来后就变成了9463847411，这就比最大的32位整数还要大了，这样的数字是没法存到int里面的，所以肯定要返回0(溢出了)。所以，我们还需要提前判断。

- INT_MAX 和 INT_MIN 可直接表示int范围

## 9.回文数

### int转换成string---to_string函数

``` cpp
string to_string (int val);
string to_string (float val);
string to_string (double val);

// to_string example  
 #include <iostream> 
 #include <string>
  
 int main ()  
 {  
    std::string pi = "pi is " + std::to_string(3.1415926);  
    std::string perfect = std::to_string(1+2+4+7+14) + " is a perfect number";  
    std::cout << pi << '\n';  
    std::cout << perfect << '\n';  
    return 0;  
 }

Output
pi is 3.141593  
28 is a perfect number
```
## 164.最大间距

### 基数排序

- 一种最简单的思路是将数组排序后再找出最大间距，但传统的基于比较的排序算法（快速排序、归并排序等）均需要 O(N\log N)O(NlogN) 的时间复杂度。我们必须使用其他的排序算法。例如，基数排序可以在 O(N)O(N) 的时间内完成整数之间的排序。
