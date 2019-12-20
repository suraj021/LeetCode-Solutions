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
        _levelOrderBottom(root, lob, 1);
        
        return lob;
    }
    
    void _levelOrderBottom(TreeNode* root, vector<vector<int>> &lob, int h){
        if(!root)   return;
        if(h > lob.size()){
            lob.insert(lob.begin(), vector<int>());
        }
        _levelOrderBottom(root->left, lob, h+1);
        _levelOrderBottom(root->right, lob, h+1);
        lob[lob.size()-h].push_back(root->val);
    }
};