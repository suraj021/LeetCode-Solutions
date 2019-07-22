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
    ListNode* oddEvenList(ListNode* head) {
        if( head == NULL || head->next == NULL || head->next->next == NULL ) {
            return head;
        }
        ListNode *oddHead = head;
        ListNode *evenHead = head->next;
        ListNode *odd, *even;
        odd= oddHead; even= evenHead;
        
        while( even && even->next ) {
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = evenHead;
        
        return oddHead;
    }
};