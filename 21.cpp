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
        ListNode* curr= NULL;
        
        if( l1== NULL )
            return l2;
        if( l2== NULL )
            return l1;
        
        if( l1->val < l2->val ){
            ListNode* n= new ListNode( l1->val );
            l1= l1->next;
            curr= n;
        }else{
            ListNode* n= new ListNode( l2->val );
            l2= l2->next;
            curr= n;
        }
        
        ListNode* dummy= curr;
        
        while( l1!= NULL && l2!= NULL ){
            if( l1->val < l2->val ){
                ListNode* n= new ListNode( l1->val );
                l1= l1->next;
                
                dummy->next= n;
                dummy= dummy->next;
                
            }else{
                
                ListNode* n= new ListNode( l2->val );
                l2= l2->next;
                
                dummy->next= n;
                dummy= dummy->next;
                
            }
        }
        
        if( l1!= NULL ){
            dummy->next= l1;
        }
        
        if( l2!= NULL ){
            dummy->next= l2;
        }
        
        
        return curr;
    }
};