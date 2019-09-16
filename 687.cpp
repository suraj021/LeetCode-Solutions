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
    int longestUnivaluePath(TreeNode* root) {
        if( root== NULL )
            return 0;
        int sameNodeLen= 0;
        _longestUnivaluePath(root, root->val, sameNodeLen);
        
        return sameNodeLen-1;
    }
    
    int _longestUnivaluePath(TreeNode* root, int val, int& sameNodeLen) {
        if( root== NULL )
            return 0;
        int l= _longestUnivaluePath(root->left, root->val, sameNodeLen);
        int r= _longestUnivaluePath(root->right, root->val, sameNodeLen);
        
        sameNodeLen= max(sameNodeLen, l+r+1);
        
        if( root->val== val )
            return max(l, r) + 1;
        return 0;
    }
};