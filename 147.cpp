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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* curr= head;
        
        while( curr ) {
            ListNode* unsortedListHead = curr->next;
            curr->next = NULL;
            dummy = mergeSortedLists(dummy, curr);
            curr = unsortedListHead;
        }
        
        return dummy->next;
    }
    
    ListNode* mergeSortedLists( ListNode *l1, ListNode *l2 ) {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *curr= dummy;
        while( l1 && l2 ) {
            if( l1->val <= l2->val ) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr->next->next= NULL;
            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        
        return dummy->next;
    }
};