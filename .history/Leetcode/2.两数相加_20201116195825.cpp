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
            p->next=l2;
            l2->val+=flag;
        }
        else if (l2==NULL&&l1!=NULL)
        {
            p->next=l1;
            l1->val+=flag;
        }
        
        return l->next;
        
    }
};

class Solution {
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

作者：l00447754
链接：https://leetcode-cn.com/problems/add-two-numbers/solution/2-liang-shu-xiang-jia-by-l00447754/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end
