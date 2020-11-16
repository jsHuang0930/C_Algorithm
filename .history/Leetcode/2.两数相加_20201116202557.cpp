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
class Solution {
//编译通过
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* node = head;
        int carry = 0;

        while (l1 || l2) {
            int val1 = 0, val2 = 0;

            if (l1) {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val2 = l2->val;
                l2 = l2->next;
            }

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            node->next = new ListNode(sum % 10);
            node = node->next;
        }
        if (carry) {
            node->next = new ListNode(carry);
        }
        return head->next;
    }
};

// class Solution {
// 编译错误
// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//         ListNode *l=new ListNode(-1);
//         ListNode p = l;
//         int flag = 0;

//         while (l1||l2 ) {
//             int _p = l1->val + l2->val + flag;
//             p->next=new ListNode(_p % 10);
//             if (_p >= 10)
//                 flag = 1;
//             else
//                 flag = 0;
//             l1 = l1->next;
//             l2 = l2->next;
//         }
//         if (l1==NULL&&l2!=NULL)
//         {
//             p->next=l2;
//             l2->val+=flag;
//         }
//         else if (l2==NULL&&l1!=NULL)
//         {
//             p->next=l1;
//             l1->val+=flag;
//         }
        
//         return l->next;
        
//     }
// };



// @lc code=end
