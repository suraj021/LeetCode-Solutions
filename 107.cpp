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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> lob;
        _levelOrderBottom(root, 0, lob);
        reverse(lob.begin(), lob.end());
        
        return lob;
    }
    
    void _levelOrderBottom(TreeNode* root, int depth, vector<vector<int>>& lob){
        if( root== NULL )   return;
        
        if( lob.size() == depth ){
            lob.push_back(vector<int>());
        }
        
        lob[depth].push_back(root->val);
        _levelOrderBottom(root->left, depth+1, lob);
        _levelOrderBottom(root->right, depth+1, lob);
    }
};