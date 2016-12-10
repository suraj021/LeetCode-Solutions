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
        
        ListNode* dummy= new ListNode( 0 );
        ListNode* curr= dummy;
        int rem= 0;
        
        while( l1!= NULL || l2!= NULL ){
            int x= (l1!= NULL)?(l1->val):0;
            int y= (l2!= NULL)?(l2->val):0;
            int sum= x + y + rem;
            
            rem= sum/10;
            
            curr->next= new ListNode( sum%10 );
            curr= curr->next;
            
            if( l1!= NULL )
                l1= l1->next;
            if( l2!= NULL )
                l2= l2->next;
        }
        
        if( rem ){
            curr->next= new ListNode( rem );
        }
        
        return dummy->next;
    }
    
};