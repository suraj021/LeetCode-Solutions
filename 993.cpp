/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if( root== NULL )
            return false;
        
        // code for recursive
        // first: parent node val
        // second: depth of node
//         map<int, pair<int,int>> node_info;
//         node_info[root->val].first= root->val;
        
//         fillDepthNodes(root, 0, node_info);
        
//         if( node_info[x].first == node_info[y].first )
//             return false;
        
//         if( node_info[x].second == node_info[y].second )
//             return true;
        
        // code for iterative
        queue<TreeNode*> qu;
        qu.push(root);
        
        while( !qu.empty() ){
            int sz= qu.size();
            bool x_exist= false;
            bool y_exist= false;
                
            for( int i= 0; i< sz; ++i ) {
                TreeNode* curr= qu.front(); qu.pop();
                if( curr->val == x ) x_exist= true;
                if( curr->val == y ) y_exist= true;
                
                if( curr->left && curr->right ) {
                    if( curr->left->val == x && curr->right->val== y || curr->left->val== y && curr->right->val ==x )
                        return false;
                }
                
                if( curr->left )
                    qu.push(curr->left);
                if( curr->right )
                    qu.push(curr->right);
            }
            
            if( x_exist && y_exist )
                return true;
            if( x_exist || y_exist )
                return false;
        }
        
        return false;
    }
    
    void fillDepthNodes(TreeNode* root, int depth, map<int,pair<int,int>>& node_info) {
        if( root== NULL )
            return;
        node_info[root->val].second = depth;
        
        if( root->left ) {
            node_info[root->left->val].first= root->val;
            fillDepthNodes(root->left, depth+1, node_info);
        }
        if( root->right ) {
            node_info[root->right->val].first= root->val;
            fillDepthNodes(root->right, depth+1, node_info);
        }
    }
};