/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int lvl_sz= q.size();
            Node* pre= NULL;
            
            for( int i= 0; i< lvl_sz; ++i ) {
                Node* node= q.front(); q.pop();
                if( pre ) {
                    pre->next= node;
                }
                pre= node;
                
                if( node->left ) q.push(node->left);
                if( node->right ) q.push(node->right);
            }
        }
        
        return root;
    }
};