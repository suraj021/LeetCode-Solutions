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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> mp;
        
        ListNode* curr = head;
        while( curr ) {
            mp[curr->val]++;
            curr= curr->next;
        }
        
        ListNode* dummy= new ListNode(INT_MIN);
        dummy->next = head;
        curr = dummy;
        
        while(curr) {
            if( curr->next && mp[curr->next->val] > 1 ) {
                ListNode* toBeDeleted = curr->next;
                curr->next = curr->next->next;
                delete toBeDeleted;
                toBeDeleted = nullptr;
            } else {
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};