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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> lot;
        _zigzagLevelOrder(root, 0, false, lot);
        
        return lot;
    }
    
    void _zigzagLevelOrder(TreeNode* root, int depth, bool flip, vector<vector<int>>& lot) {
        if(!root) return;
        if( lot.size()== depth ){
            vector<int> nodes;
            lot.push_back(nodes);
        }
        if( flip ) lot[depth].insert(lot[depth].begin(), root->val);
        else lot[depth].push_back(root->val);
        
        _zigzagLevelOrder(root->left, depth+1, !flip, lot);
        _zigzagLevelOrder(root->right, depth+1, !flip, lot);
    }
};