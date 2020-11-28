/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        //注意这里是没有头节点的
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *tmp = newhead->next;
        ListNode *pre = newhead;
        while (tmp) //注意终止条件
        {
            if (tmp->val == val)
            {
                pre->next = tmp->next;
                tmp = tmp->next;
            }
            else
            {
                pre = tmp;
                tmp = tmp->next;
            }
        }
        return newhead->next;
    }
};
// @lc code=end
