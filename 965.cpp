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
    bool isUnivalTree(TreeNode* root) {
        if( root== NULL )
            return false;
        return _isUnivalTree(root, root->val);
    }
    
    bool _isUnivalTree(TreeNode* root, int val) {
        if( root == NULL || root->val != val )
            return false;
        bool lf= root->left ? _isUnivalTree(root->left, val) : true;
        bool rt= root->right ? _isUnivalTree(root->right, val) : true;
        return lf & rt;
    }
};