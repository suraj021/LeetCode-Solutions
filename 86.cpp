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
    ListNode* partition(ListNode* head, int x) {
        if( head == NULL ) {
            return head;
        }
        
        ListNode dummy(-1);
        dummy.next= head;
        ListNode* curr= &dummy;
        
        while( curr->next && curr->next->val < x ) {
            curr= curr->next;
        }
        
        ListNode* nextPtr= curr->next;
        ListNode* fwdPtr= nextPtr;
        
        while( fwdPtr && fwdPtr->next ) {
            if( fwdPtr->next->val < x ) {
                curr->next = fwdPtr->next;
                fwdPtr->next = fwdPtr->next->next;
                curr->next->next = nextPtr;
                curr= curr->next;
            } else {
                fwdPtr= fwdPtr->next;
            }
        }
        
        return dummy.next;
    }
};