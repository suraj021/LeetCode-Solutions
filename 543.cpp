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
    int diameterOfBinaryTree(TreeNode* root) {
        if( root== NULL )   return 0;
        int maxd= INT_MIN;
        _diameterOfBinaryTree(root, maxd);
        
        return maxd-1;
    }
    
    int _diameterOfBinaryTree(TreeNode* root, int& maxd){
        if( root== NULL )
            return 0;
        int l= _diameterOfBinaryTree(root->left, maxd);
        int r= _diameterOfBinaryTree(root->right, maxd);
        
        maxd= max( maxd, l+r+1 );
        
        return max(l,r) + 1;
    }
    
    
};