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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if( !l2 ) return l1;
        if( !l1 ) return l2;
        
        int len1 = list_length(l1);
        int len2 = list_length(l2);
        
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        
        while( len1 || len2 ) {
            int sum = 0;
            if( len1 && len2 ) {
                if( len1 > len2 ) { sum = l1->val; len1--; l1= l1->next; }
                else if( len2 > len1 ) { sum = l2->val; len2--; l2= l2->next; }
                else { 
                    sum = l1->val + l2->val;
                    l1= l1->next;
                    l2= l2->next;
                    len1--; len2--;
                }   
            } else if( len1 ) { 
                sum = l1->val;
                len1--; 
                l1= l1->next; 
            } else { 
                sum = l2->val;
                len2--;
                l2= l2->next; 
            }
            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = curr->next;
        }
        
        vector<ListNode*> sumList;
        
        curr = dummyHead->next;
        
        while( curr ) {
            sumList.push_back(curr);
            curr= curr->next;
        }
        
        int carry = 0;
        for( int i= sumList.size()-1; i>= 0; --i ) {
            int sum= sumList[i]->val + carry;
            carry = sum/10;
            sumList[i]->val = sum%10;
        }
        
        if( carry ) {
            ListNode* n = new ListNode(1);
            n->next = dummyHead->next;
            dummyHead->next = n;
        }
        
        return dummyHead->next;
    }
    
    int list_length(ListNode* head) {
        ListNode* curr = head;
        int len = 0;
        
        while( curr ) {
            len++;
            curr = curr->next;
        }
        
        return len;
    }
};