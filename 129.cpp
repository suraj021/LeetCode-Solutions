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
    int sumNumbers(TreeNode* root) {
        int sum= 0;
        _sumNumbers(root, 0, sum);
        
        return sum;
    }
    
    void _sumNumbers(TreeNode* root, int currSum, int& sum) {
        if(!root) return;
        
        currSum= (10*currSum + root->val);
        
        if( !root->left && !root->right ){
            sum+= currSum;
        }
        
        if(root->left)
            _sumNumbers(root->left, currSum, sum);
        if(root->right)
            _sumNumbers(root->right, currSum, sum);
    }
};