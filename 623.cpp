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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if( d== 1 ){
            TreeNode* newRoot= new TreeNode(v);
            newRoot->left= root;
            return newRoot;
        } else {
            _addOneRow(root, v, d-1);
            return root;
        }
    }
    
    void _addOneRow(TreeNode* root, int v, int d) {
        if(!root) return;
        
        if( d== 1 ){
            TreeNode* lnode= new TreeNode(v);
            TreeNode* rnode= new TreeNode(v);
            lnode->left= root->left;
            rnode->right= root->right;
            root->left= lnode;
            root->right= rnode;
        } else {
            _addOneRow(root->left, v, d-1);
            _addOneRow(root->right, v, d-1);
        }
    }
};