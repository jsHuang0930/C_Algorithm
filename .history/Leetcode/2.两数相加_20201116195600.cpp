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

// class Solution {
// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//         ListNode *l,*p;
//         l=new ListNode;
//         l->next=NULL;
//         p = l;
//         int flag = 0;

//         while (l1!= NULL && l2 != NULL) {
//             int _p = l1->val + l2->val + flag;

//             p->next->val = _p % 10;

//             if (_p >= 10)
//                 flag = 1;
//             else
//                 flag = 0;
//             l1 = l1->next;
//             l2 = l2->next;
//         }
//         if (l1==NULL&&l2!=NULL)
//         {
//             p=l2;
//             l2->val+=flag;
//         }
//         else if (l2==NULL&&l1!=NULL)
//         {
//             p=l1;
//             l1->val+=flag;
//         }
        
//         return l;
        
//     }
// };


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l=new ListNode(-1);
        ListNode p = l;
        int flag = 0;

        while (l1||l2 ) {
            int _p = l1->val + l2->val + flag;
            p->next=new ListNode(_p % 10);
            if (_p >= 10)
                flag = 1;
            else
                flag = 0;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1==NULL&&l2!=NULL)
        {
            p.n=l2;
            l2->val+=flag;
        }
        else if (l2==NULL&&l1!=NULL)
        {
            p=l1;
            l1->val+=flag;
        }
        
        return l;
        
    }
};
// @lc code=end
