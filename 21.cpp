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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while( l1 && l2 ) {
            ListNode* newNode;
            int v = min( l1->val, l2->val );
            newNode = new ListNode(v);
            if( l1->val == v ) {
                l1= l1->next;
            } else {
                l2= l2->next;
            }
            curr->next = newNode;
            curr= curr->next;
        }

        if( l1 ) {
            curr->next = l1;
        } else if( l2 ) {
            curr->next = l2;
        }
        
        return dummy->next;
    }
};