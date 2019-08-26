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
    int rob(TreeNode* root) {
        map<TreeNode*, int> robVal;
        _rob(root, robVal);
        
        return robVal[root];
    }
    
    int _rob(TreeNode* root, map<TreeNode*, int>& robVal){
        if(!root) return 0;
        
        if( robVal.find(root)!= robVal.end() )
            return robVal[root];
        
        int val= 0;
        
        if( root->left ) {
            val+= _rob(root->left->left, robVal) + _rob(root->left->right, robVal);
        }
        if( root->right ) {
            val+= _rob(root->right->left, robVal) + _rob(root->right->right, robVal);
        }
        robVal[root]= max( root->val + val, _rob(root->left, robVal) + _rob(root->right, robVal) );
        
        return robVal[root];
    }

};