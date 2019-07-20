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
    ListNode* swapPairs(ListNode* head) {
        
        // if( head->next)
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        
        while( curr->next ) {
            ListNode* n = curr->next;
            ListNode* m = curr->next->next;
                  
            if( !m ) {
                break;
            }
            
            n->next = m->next;
            m->next = n;
            curr->next = m;
            
            curr = n;
        }
        
        return dummy->next;
    }
};