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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if( headA == headB ) {
            return headA;
        }
        
        int lenA = listLength(headA);
        int lenB = listLength(headB);
        
        int diff = lenA - lenB;
        
        return (diff > 0) ? _getIntersectionNode(diff, headA, headB) : _getIntersectionNode(abs(diff), headB, headA);
    }
    
    ListNode *_getIntersectionNode(int d, ListNode *headA, ListNode *headB){
                
        ListNode *currA, *currB;
        currA = headA; currB = headB;
        
        while( d > 0 ) {
            if( !currA ) {
                return NULL;
            }
            d--;
            currA= currA->next;
        }
        
        while( currA && currB ) {
            if( currA == currB ) {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        return NULL;
    }
    
    int listLength(ListNode* head) {
        ListNode* curr = head;
        int len= 0;
        
        while( curr ) {
            len++;
            curr= curr->next;
        }
        
        return len;
    }
};