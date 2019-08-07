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
        int height= 0;
        return _isBalanced(root, height);
    }
    
    bool _isBalanced(TreeNode* root, int& height) {
        if( root== NULL ) {
            height= 0;
            return true;
        }
        
        int lh, rh;
        lh= rh= 0;
        
        bool lbal, rbal;
        lbal= rbal= false;
        
        lbal= _isBalanced(root->left, lh);
        rbal= _isBalanced(root->right, rh);
        
        height= max(lh, rh) + 1;
        
        if( abs(rh-lh) > 1 )
            return false;
        else
            return lbal && rbal;
    }
};