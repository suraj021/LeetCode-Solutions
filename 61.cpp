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
    ListNode* rotateRight(ListNode* head, int k) {
        if( head== NULL ) return head;
        
        k = k%listLength(head);
        if( k ) {
            ListNode *fwdptr, *backptr;
            fwdptr= backptr= head;
            for( int i= 0; i< k; ++i )
                fwdptr= fwdptr->next;
            while( fwdptr->next ) {
                fwdptr= fwdptr->next;
                backptr= backptr->next;
            }
            fwdptr->next= head;
            head= backptr->next;
            backptr->next = NULL;
        }
        return head;
    }
    
    int listLength(ListNode* head) {
        int len= 0;
        ListNode* curr= head;
        
        while( curr ) {
            len++;
            curr = curr->next;
        }
        return len;
    }
};