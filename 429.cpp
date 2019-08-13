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
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> lorder;
        
        if( root== NULL )
            return lorder;

        int depth= 0;
        queue<Node*> q;
        
        q.push(root);

        for( int d= 0; !q.empty(); ++d ){
            if( lorder.size() == d )    lorder.resize(d+1);
            int qsz= q.size();
            
            for( int i= 0; i< qsz; ++i ){
                Node* curr= q.front(); q.pop();
                lorder[d].push_back(curr->val);
                
                for(auto child: curr->children)
                    q.push(child);
            }
        }
        
        return lorder;
    }
    
    void _levelOrder(Node* root,int depth, vector<vector<int>>& lorder){
        if( root== NULL ) return;
        if( lorder.size() == depth ) lorder.resize(depth+1);
        lorder[depth].push_back(root->val);
        
        for( auto child: root->children ){
            _levelOrder(child, depth+1, lorder);
        }
    }
};