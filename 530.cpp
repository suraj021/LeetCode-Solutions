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
    int getMinimumDifference(TreeNode* root) {
        int min_diff= INT_MAX;
        TreeNode* pre= NULL;
        _getMinimumDifference(root, pre, min_diff);
        return min_diff;
    }
    
    void _getMinimumDifference(TreeNode* root, TreeNode*& pre, int& min_diff){
        if(!root) return;
        _getMinimumDifference(root->left, pre, min_diff);
        
        if( pre ) {
            min_diff= min( min_diff, root->val-pre->val);
        }
        
        pre= root;
        _getMinimumDifference(root->right, pre, min_diff);
    }
};