/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        
        Node* curr = head;
        while( curr ) {
            Node* node = new Node(curr->val, NULL, NULL);
            mp[curr] = node;
            curr= curr->next;
        }
        
        curr = head;
        while( curr ) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr= curr->next;
        }
        
        return mp[head];
    }
};