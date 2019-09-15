/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if( root== NULL )
            return 0;
        
        queue<Node*> q;
        q.push(root);
        int mxd= 0;
        
        for( mxd= 0; !q.empty(); ++mxd ){
            int sz= q.size();
            while( sz-- ) {
                Node* curr= q.front(); q.pop();
                for(auto child: curr->children){
                    q.push(child);
                }
            }
        }
        
        return mxd;
    }
    
    int _maxDepth(Node* root) {
        if( root== NULL )
            return 0;
        int max_depth= 0;
        
        for(auto child: root->children){
            max_depth= max( max_depth, _maxDepth(child));
        }
        
        return 1+max_depth;
    }
};