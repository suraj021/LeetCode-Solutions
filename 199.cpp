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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rside;
        _rightSideView(root, 1, rside);
        return rside;
    }
    
    void _rightSideView(TreeNode* root, int depth, vector<int>& rside){
        if(!root)   return;
        if( rside.size() < depth )  rside.push_back(root->val);
        _rightSideView(root->right, depth+1, rside);
        _rightSideView(root->left, depth+1, rside);
    }
};