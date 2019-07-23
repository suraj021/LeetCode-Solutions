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
    void reorderList(ListNode* head) {
        if( head == NULL ) 
            return;
        
        // Find middle of node
        ListNode *slow, *fast;
        slow = fast = head;
        while( fast && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Break the list into halves
        ListNode* tailHead = slow->next;
        slow->next = NULL;
        
        // reverse the tail part
        tailHead = reverse( tailHead );
        
        ListNode* headHead = head;
        
        // merge the lists
        while( tailHead && headHead ) {
            ListNode* tailNext = tailHead->next;
            ListNode* headNext = headHead->next;
            headHead->next = tailHead;
            tailHead->next = headNext;
            
            headHead = headNext;
            tailHead = tailNext;
        }
    }
    
    ListNode* reverse(ListNode* head) {
        if( head== NULL || head->next == NULL )
            return head;
        ListNode* newHead = reverse( head->next );
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
};