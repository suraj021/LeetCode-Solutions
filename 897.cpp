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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* curr= root;
        TreeNode* prev= NULL;
        TreeNode* newRoot= NULL;

//         while( curr || !s.empty() ){
//             while( curr ) {
//                 s.push(curr);
//                 curr= curr->left;
//             }
//             curr= s.top(); s.pop();
            
//             if( prev ) {
//                 curr->left= NULL;
//                 prev->right= curr;
//             } else {
//                 newRoot= curr;
//                 newRoot->left= NULL;
//             }
//             prev= curr;
//             curr= curr->right;
//         }
        _increasingBST(root, prev, newRoot);
        
        return newRoot;
    }
    
    void _increasingBST(TreeNode* root, TreeNode*& prev, TreeNode*& newRoot ) {
        if( root== NULL )
            return;
        _increasingBST(root->left, prev, newRoot);

        
        if( prev ) {
            root->left= NULL;
            prev->left= NULL;
            prev->right= root;
            prev= root;

        } else {
            newRoot= root;
            prev= newRoot;
        }
        
        _increasingBST(root->right, prev, newRoot);

    }
    
    
};