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


// class Solution {
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

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head = new ListNode(-1);
//         ListNode* node = head;
//         int carry = 0;

//         while (l1 || l2) {
//             int val1 = 0, val2 = 0;

//             if (l1) {
//                 val1 = l1->val;
//                 l1 = l1->next;
//             }
//             if (l2) {
//                 val2 = l2->val;
//                 l2 = l2->next;
//             }

//             int sum = val1 + val2 + carry;
//             carry = sum / 10;

//             node->next = new ListNode(sum % 10);
//             node = node->next;
//         }
//         if (carry) {
//             node->next = new ListNode(carry);
//         }
//         return head->next;
//     }
// };

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int temp = 0;
        ListNode l3 = new ListNode(0);
        ListNode p = l3;
        while(l1 != null || l2 != null || temp != 0){
        int l1Val = l1 != null ? l1.val : 0;
        int l2Val = l2 != null ? l2.val : 0;
        int sumVal = l1Val + l2Val + temp;
        temp = sumVal/10;
        p.next = new ListNode(sumVal%10);
        p = p.next;
        if(l1 != null) l1 = l1.next;
        if(l2 != null) l2 = l2.next;
        }
        return l3.next;
    }
}

// @lc code=end
