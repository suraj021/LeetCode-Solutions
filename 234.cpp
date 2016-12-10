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
    bool isPalindrome(ListNode* head) {
        
        if( head== NULL )
            return true;
        
        ListNode* mid= middle( head );
        ListNode* l2= mid->next;
        ListNode* l1= head;
        l2= reverse( l2 );
        
        while( l2!= NULL ){
            int x= l2->val;
            int y= l1->val;
            
            if( x!= y )
                return false;
            l1= l1->next;
            l2= l2->next;
        }
        
        return true;
    }
    
    ListNode* middle( ListNode* head ){
        ListNode* slow= head;
        ListNode* fast= head->next;
        
        while( fast!= NULL && fast->next!= NULL ){
            slow= slow->next;
            fast= fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse( ListNode* head ){
        ListNode* prev= NULL;
        ListNode* curr= head;
        ListNode* next;
        
        while( curr!= NULL ){
            next= curr->next;
            curr->next= prev;
            prev= curr;
            curr= next;
        }
        return prev;
    }
};