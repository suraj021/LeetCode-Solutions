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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if( m == n ) {
            return head;
        }
        
        ListNode dummy(0);
        ListNode* curr= &dummy;
        dummy.next = head;
        
        for( int i= 1; i< m; ++i ) {
            curr= curr->next;
        }
        
        ListNode* tail = curr->next;
        
        for( int i= 0; i< n-m; ++i ) {
            ListNode* temp = curr->next;
            curr->next = tail->next;
            tail->next = tail->next->next;
            curr->next->next = temp;
        }
        
        return dummy.next;
    }
};