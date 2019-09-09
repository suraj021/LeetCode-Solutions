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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return root;
        map<TreeNode*, bool> mp;
        setPruneCondition(root, mp);
        
        if(!mp[root]){
            return NULL;
        }
        _pruneTree(root, mp);
        
        return root;
    }
    
    void _pruneTree(TreeNode* root, map<TreeNode*, bool>& mp) {
        if(!root) return;
        if(!mp[root->left])
            root->left= NULL;
        if(!mp[root->right])
            root->right= NULL;
        _pruneTree(root->left, mp);
        _pruneTree(root->right, mp);
    }
    
    bool setPruneCondition(TreeNode* root, map<TreeNode*, bool>& mp){
        if(!root)   return false;
        
        bool lp= setPruneCondition(root->left, mp);
        bool rp= setPruneCondition(root->right, mp);
        
        mp[root]= lp || rp || (root->val== 1);
        
        return mp[root];
    }
};