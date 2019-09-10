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
    int minDiffInBST(TreeNode* root) {
        int node_diff= min( abs(root->val-maxInTree(root->left)), abs(maxInTree(root->right)-root->val));
        int left_diff= root->left ? minDiffInBST(root->left) : INT_MAX;
        int right_diff= root->right ? minDiffInBST(root->right) : INT_MAX;
        return min( node_diff, min(left_diff, right_diff));
    }
    
    int maxInTree(TreeNode* root) {
        if( !root ) 
            return INT_MAX;
        TreeNode* curr= root;
        while( curr->right )
            curr= curr->right;
        return curr->val;
    }
};