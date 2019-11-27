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
        ListNode* dummy= new ListNode(0);
        dummy->next = head;
        ListNode *slow, *fast;
        slow= fast= dummy;
        
        for(int i= 0; i< n && fast->next; ++i){
            fast= fast->next;
        }
        
        while(fast && fast->next){
            slow= slow->next;
            fast= fast->next;
        }
        
        ListNode* ptr= slow->next;
        
        slow->next= slow->next->next;
        
        delete ptr;
        ptr= nullptr;
        
        return dummy->next;
    }
};