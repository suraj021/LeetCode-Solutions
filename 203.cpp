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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* curr = dummy;
        
        while( curr && curr->next ) {
            if( curr->next->val == val ) {
                ListNode *toBeDeleted = curr->next;
                curr->next = curr->next->next;
                delete toBeDeleted;
                toBeDeleted = nullptr;
            } else {
                curr= curr->next;
            }
        }
        
        return dummy->next;
    }
};