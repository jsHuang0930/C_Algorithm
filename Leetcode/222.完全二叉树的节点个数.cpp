/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{ //深度遍历O(n)
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

class Solution
{
    //二分查找+位运算
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int level = 0;
        TreeNode *node = root;
        while (node->left != nullptr)
        {
            level++;
            node = node->left;
        }
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high)
        {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }

    bool exists(TreeNode *root, int level, int k)
    {
        int bits = 1 << (level - 1);
        TreeNode *node = root;
        while (node != nullptr && bits > 0)
        {
            if (!(bits & k))
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
};
// @lc code=end
