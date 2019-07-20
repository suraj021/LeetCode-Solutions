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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if( lists.size() == 0 ) {
            return NULL;
        }
        
        int first = 0;
        int last = lists.size()-1;
        
        while( first < last ) {
            int i = first, j = last;
            
            while( i < j ) {
                lists[i] = this->mergeTwoLists( lists[i], lists[j] );
                i++; j--;
            }
            last/= 2;
        }
        
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while( l1 && l2 ) {
            ListNode* newNode;
            int v = min( l1->val, l2->val );
            newNode = new ListNode(v);
            if( l1->val == v ) {
                l1= l1->next;
            } else {
                l2= l2->next;
            }
            curr->next = newNode;
            curr= curr->next;
        }

        if( l1 ) {
            curr->next = l1;
        } else if( l2 ) {
            curr->next = l2;
        }
        
        return dummy->next;
    }
};