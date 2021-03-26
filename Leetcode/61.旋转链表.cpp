/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next){}
                                                  *
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *now = head;
        ListNode *flag = head;
        int n = 1;
        int a;
        if (k == 0 || head == nullptr || head->next == nullptr)
        {
            return head;
        }
        while (now->next)
        { //计数
            now = now->next;
            n++;
        }
        a = n - (k % n);
        if (a == n) //刚好整除
        {
            return head;
        }
        while ((a--) - 1)
        {
            flag = flag->next;
        }
        ListNode *newhead = flag->next;
        flag->next = nullptr;
        now->next = head;
        return newhead;
    }
};

// @lc code=end
