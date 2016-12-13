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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len= length( head );
        int k= len-n;
        
        if( len== 0 )
            return NULL;
        
        if( k== 0 ){
            ListNode* curr= head->next;
            head->next= NULL;
            delete head;
            return curr;
        }else if( n== 1 ){
            ListNode* curr= head;
            for( int i= 1; i< len-1; ++i )
                curr= curr->next;
            ListNode* del= curr->next;
            curr->next= NULL;
            
            delete del;
        }else{
            ListNode* curr= head;
            for( int i= 1; i< k; ++i )
                curr= curr->next;
                
            ListNode* del= curr->next;
            curr->next= del->next;
            
            delete del;
            
        }
        
        return head;
    }
    
    int length( ListNode* head ){
        int l= 0;
        
        while( head!= NULL ){
            l++;
            head= head->next;
        }
        return l;
    }
};