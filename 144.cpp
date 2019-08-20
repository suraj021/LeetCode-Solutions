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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        TreeNode* curr= root;
        stack<TreeNode*> s;
        
        while( curr || !s.empty() ) {
            while( curr ) {
                pre.push_back(curr->val);
                s.push(curr);
                curr= curr->left;
            }
            
            curr= s.top(); s.pop();
            curr= curr->right;
        }
        
        // _preorder(root, pre);
        return pre;
    }
    
    void _preorder(TreeNode* root, vector<int>& pre) {
        if( root ) {
            pre.push_back(root->val);
            _preorder(root->left, pre);
            _preorder(root->right, pre);
        }
    }
    
    
};