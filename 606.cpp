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
    string tree2str(TreeNode* t) {
        if(!t)  return "";
        string lstr= tree2str(t->left);
        string rstr= tree2str(t->right);
        
        if( lstr== "" && rstr== "" ){
            return to_string(t->val);
        }else if(lstr== ""){
            return to_string(t->val) + "()" + "("+ rstr +")";
        }else {
            lstr= (lstr!="") ? "(" + lstr + ")" : "";
            rstr= (rstr!="") ? "(" + rstr + ")" : "";
            return to_string(t->val) + lstr + rstr ;    
        }
    }
};