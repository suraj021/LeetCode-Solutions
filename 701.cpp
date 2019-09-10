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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)   return new TreeNode(val);
        TreeNode* curr= root;
        TreeNode* pre= NULL;
        
        while(curr){
            pre= curr;
            if(val > curr->val)
                curr= curr->right;
            else
                curr= curr->left;
        }
        
        if( pre->val > val ){
            pre->left= new TreeNode(val);
        } else {
            pre->right= new TreeNode(val);
        }
        
        return root;
    }
    
    TreeNode* _insertIntoBST(TreeNode* root, int val){
        if(!root)   return new TreeNode(val);
        if(val < root->val)
            root->left= _insertIntoBST(root->left, val);
        else
            root->right= _insertIntoBST(root->right, val);
        
        return root;
    }
};