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
    int numComponents(ListNode* head, vector<int>& G) {
        if( G.size() == 0 || G.size() == 1 ) {
            return G.size();
        }
        
        sort( G.begin(), G.end() );
        
        int ans = 0;
        int index = 0;
        
        ListNode* curr = head;
        
        while( curr ) {
            bool pre = false;
            
            while( curr!= NULL && find(G.begin(), G.end(), curr->val)!= G.end() ) {
                pre = true;
                curr = curr->next;
            }
            
            if( pre ) {
                ans++;
            } else {
                curr = curr->next;
            }
        }
        
        return ans;
    }
};