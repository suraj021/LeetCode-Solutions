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
    int sumOfLeftLeaves(TreeNode* root) {
        if( root == NULL )
            return 0;
        
        int sum= 0;
        // _sumOfLeftLeaves(root, false, sum);
        stack<TreeNode*> node_stack;
        stack<bool> add_flag;
        
        node_stack.push(root);
        add_flag.push(false);
        
        while(!node_stack.empty()){
            TreeNode* curr= node_stack.top(); node_stack.pop();
            bool flag= add_flag.top(); add_flag.pop();
            
            sum+= flag && !curr->left && !curr->right ? curr->val : 0;
            
            if( curr->left ){
                node_stack.push(curr->left);
                add_flag.push(true);
            }
            
            if( curr->right ) {
                node_stack.push(curr->right);
                add_flag.push(false);
            }
        }
        
        return sum;
    }
    
    void _sumOfLeftLeaves(TreeNode* root, bool add, int& sum ) {
        if( !root )
            return;
        sum+= add && !root->left && !root->right ? root->val : 0;
        if( root->left ) _sumOfLeftLeaves(root->left, true, sum);
        if( root->right ) _sumOfLeftLeaves(root->right, false, sum);
    }
};