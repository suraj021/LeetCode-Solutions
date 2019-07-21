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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans;
        
        if( k == 1 ) {
            ans.push_back(root);
            return ans;
        }
        
        int list_len = linkedListLength(root);
        
        int each_node_len = list_len/k;
        int extra = list_len%k;
        ListNode* curr = root;
            
        for( int i= 0; i< k; ++i ){
            int len = each_node_len + ( extra ? 1 : 0 );
            if( len ) {
                ans.push_back(curr);
                while(len-- > 1) curr= curr->next;
                ListNode* next_node = curr->next;
                curr->next = NULL;
                curr = next_node;
            } else {
                ans.push_back(NULL);
            }
            extra-= extra ? 1 : 0;
        }
        
        return ans;
    }
    
    int linkedListLength(ListNode* head) {
        ListNode* curr = head;
        int len = 0;
        
        while(curr){
            len++;
            curr= curr->next;
        }
        
        return len;
    }
};