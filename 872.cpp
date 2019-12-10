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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1, s2;
        s1= s2= "";
        
        dfs(root1, s1);
        dfs(root2, s2);
        
        return s1==s2;
    }
    
    void dfs(TreeNode* root, string &s){
        if(!root) return;
        if( !root->left && !root->right )
            s+= to_string(root->val) + "#";
        dfs(root->left, s);
        dfs(root->right, s);
    }
};