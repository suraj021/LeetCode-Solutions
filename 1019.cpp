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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> list = this->flatList(head);
        int list_size = (int)list.size();
        
        vector<int> ans (list_size);
        stack<int> s;
        
        for( int i= list_size-1; i>= 0; --i ){
            while( !s.empty() && s.top() <= list[i] ) {
                s.pop();
            }
            ans[i]= s.empty() ? 0 : s.top();
            s.push(list[i]);
        }
        
        return ans;
    }
    
    vector<int> flatList(ListNode* head ) {
        vector<int> list;
        ListNode* curr = head;
        
        while( curr ) {
            list.push_back(curr->val );
            curr= curr->next;
        }
        
        return list;
    }
};