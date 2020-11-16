/*
 * @lc app=leetcode.cn id=2 lang=java
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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

