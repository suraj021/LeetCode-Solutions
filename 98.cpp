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
    bool isValidBST(TreeNode* root) {
        // return _isValidBST(root, NULL, NULL);
        stack<TreeNode *> s;
        TreeNode* curr = root;
        TreeNode* pre = NULL;
        
        while( curr || !s.empty() ) {
            while( curr ) {
                s.push(curr);
                curr= curr->left;
            }
            
            curr= s.top();
            s.pop();
            
            if( pre && pre->val >= curr->val ) {
                return false;
            }
            
            pre= curr;
            curr= curr->right;
        }
        
        return true;
    }
    
    bool _isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if( root== NULL ) {
            return true;
        }
        
        if( minNode && minNode->val >= root->val || maxNode && maxNode->val <= root->val ){
            return false;
        }
        
        return _isValidBST(root->left, minNode, root ) && _isValidBST(root->right, root, maxNode);
    }
};