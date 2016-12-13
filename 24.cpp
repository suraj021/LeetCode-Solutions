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
        if( head== NULL )
            return head;
        if( head->next== NULL )
            return head;
            
        ListNode* dummy= new ListNode( INT_MIN );
        dummy->next= head;
        
        ListNode* b= head;
        ListNode* f= head->next;
        ListNode* prev= dummy;
        
        while( f!= NULL && b!= NULL ){
            b->next= f->next;
            f->next= b;
            prev->next= f;
            
            prev= b;
            b= b->next;
            
            if( b== NULL )
                break;
            f= b->next;
        }
        
        return dummy->next;
    }
};