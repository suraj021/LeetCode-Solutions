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
    TreeNode* convertBST(TreeNode* root) {
        int addVal= 0;
        // _convertBST(root, addVal);
        
        stack<TreeNode*> s;
        TreeNode* curr= root;
        
        while( curr || !s.empty() ){
            while( curr ) {
                s.push(curr);
                curr= curr->right;
            }
            
            curr= s.top(); s.pop();
            
            int nodeVal= curr->val;
            curr->val+= addVal;
            addVal+= nodeVal;
            
            curr= curr->left;
        }
        
        return root;
    }
    
    void _convertBST(TreeNode* root, int& addVal){
        if( root) {
            _convertBST(root->right, addVal);
            int nodeVal= root->val;
            root->val+= addVal;
            addVal+= nodeVal;
            _convertBST(root->left, addVal);
        }
    }
};