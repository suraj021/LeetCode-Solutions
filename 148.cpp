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
    ListNode* sortList(ListNode* head) {
        if( head== NULL || head->next== NULL )
            return head;
        
        // find the centre and break it into two lists
        ListNode *slow, *fast;
        slow= fast= head;
        
        while( fast && fast->next && fast->next->next ){
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode* tailHead = slow->next;
        slow->next= NULL;
        
        ListNode *leftSortedHead = sortList(head);
        ListNode *rightSortedHead = sortList(tailHead);
        
        return mergeSortedLists(leftSortedHead, rightSortedHead);
    }
    
    ListNode* mergeSortedLists(ListNode* left, ListNode* right) {
        ListNode *dummy= new ListNode(-1);
        ListNode *curr= dummy;
        
        while( left && right ) {
            if( left->val < right->val ) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            
            curr= curr->next;
        }
        
        if( left ) {
            curr->next = left;
        }
        if( right ) {
            curr->next = right;
        }
        
        return dummy->next;
    }
};