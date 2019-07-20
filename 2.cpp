/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy; 
        int carry = 0;
        while(l1 || l2) {
            int sum = ( l1 ? l1->val : 0 ) + ( l2 ? l2->val : 0 ) + carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            curr->next = newNode;
            curr= curr->next;
        }
        
        if( carry ) {
            curr->next = new ListNode(carry);
        } 
        
        return dummy->next;
    }
};