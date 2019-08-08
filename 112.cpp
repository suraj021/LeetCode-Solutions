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
    bool hasPathSum(TreeNode* root, int sum) {
        
        if( root== NULL ) 
            return false;
        
        stack<TreeNode*> node_stack;
        stack<int> sum_stack;
        
        node_stack.push(root); sum_stack.push(root->val);
        
        while( !node_stack.empty() ) {
            TreeNode* curr= node_stack.top(); node_stack.pop();
            int path_sum= sum_stack.top(); sum_stack.pop();
            
            if(!curr->left && !curr->right && path_sum == sum )
                return true;
            
            if(curr->left) {
                node_stack.push(curr->left);
                sum_stack.push(path_sum + curr->left->val);
            }
            if(curr->right){
                node_stack.push(curr->right);
                sum_stack.push(path_sum + curr->right->val);
            }
        }
        
        return false;
    }
    
    bool _hasPathSum(TreeNode* root, int sum) {
        if( root== NULL )
            return false;
        if( !root->left && !root->right )
            return root->val == sum;

        return _hasPathSum(root->left, sum-root->val) || _hasPathSum(root->right, sum-root->val);
    }
    
};