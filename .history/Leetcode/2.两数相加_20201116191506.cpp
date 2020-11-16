/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode *l;
            ListNode *p = l;
            int flag = 0;

            while (l1!= null && l2 != null) {
                int _p = l1->val + l2->val + flag;
                p->val = _p % 10;

                if (_p >= 10)
                    flag = 1;
                else
                    flag = 0;
                p = p->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            if (l1==null)
            {
                p=l2;
                l2->val=
            }
            
        }
    };
    // @lc code=end
