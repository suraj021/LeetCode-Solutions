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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string ss = "";
        string tt = "";
        
        serialize(s, ss);
        serialize(t, tt);
        
        cout << ss << " " << tt << endl;
        
        return ss.find(tt) != string::npos;
    }
    
    void serialize(TreeNode* root, string &s){
        if(!root){
            s+= "?";
            return;
        }
        s+= "#" + to_string(root->val) + "#";
        serialize(root->left, s);
        serialize(root->right, s);
    }
};