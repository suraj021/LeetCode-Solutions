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
    TreeNode* invertTree(TreeNode* root) {
        if( !root ) {
            return NULL;
        }
        
        stack<TreeNode*> s;
        s.push(root);
        
        while( !s.empty() ){
            TreeNode* curr= s.top(); s.pop();
            
            TreeNode* temp= curr->left;
            curr->left= curr->right;
            curr->right= temp;
            
            if( curr->left )
                s.push(curr->left);
            if( curr->right )
                s.push(curr->right);
        }
        
        return root;
    }
    
    TreeNode* _invertTree(TreeNode* root) {
        if( root== NULL )
            return root;
        TreeNode* temp= root->left;
        root->left = root->right;
        root->right= temp;
        
        if( root->left )
            root->left = _invertTree(root->left);
        if( root->right )
            root->right = _invertTree(root->right);
        
        return root;
    }
};