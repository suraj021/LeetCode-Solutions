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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next= head;
        int len= 0;
        
        ListNode* curr = head;
        while( curr ) {
            len++;
            curr= curr->next;
        }
        
        curr= &dummy;
        while( len>= k ) {
            ListNode* tail= curr->next;
            for( int i= 1; i< k; ++i ) {
                ListNode* temp = curr->next;
                curr->next = tail->next;
                tail->next = curr->next->next;
                curr->next->next = temp;
            }
            len-= k;
            curr = tail;
        }
        
        return dummy.next;
    }
};