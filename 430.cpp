/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while( curr ) {
            if( curr->child ) {
                Node* next_node = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;
                
                Node* temp = curr->next;
                while( temp->next ) {
                    temp = temp->next;
                }
                
                if( next_node ) {
                    temp->next = next_node;
                    next_node->prev = temp;
                }
            }
            curr = curr->next;
        }
        
        return head;
    }
};