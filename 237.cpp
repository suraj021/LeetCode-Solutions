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
    void deleteNode(ListNode* node) {
        // *node = *(node->next);
        ListNode* nextNode= node->next;
        node->val= node->next->val;
        node->next= nextNode->next;
        
        delete nextNode;
        nextNode= nullptr;
    }
};