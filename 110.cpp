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
    bool isBalanced(TreeNode* root) {
        bool ans= true;
        _isBalanced(root, ans);
        
        return ans;
    }
    
    int _isBalanced(TreeNode* root, bool &ans){
        if(!root)   return 0;
        int l= _isBalanced(root->left, ans);
        int r= _isBalanced(root->right, ans);
        
        if( abs(l-r) > 1 ) ans= false;
        
        return max(l, r) + 1;
    }
};