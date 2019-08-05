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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        TreeNode *p, *q;
        p= q= root;
        
        while( p || !s1.empty() && q || !s2.empty() ) {
            while( p ) {
                s1.push(p);
                p= p->left;
            }
            while( q ) {
                s2.push(q);
                q= q->right;
            }
            
            p= s1.top(); s1.pop();
            q= s2.top(); s2.pop();
            
            if( s1.size() != s2.size() || p->val != q->val ) {
                return false;
            }
            
            p= p->right;
            q= q->left;
        }
        
        return true;
    }
    
    bool _isSymmetric(TreeNode* p, TreeNode* q){
        if( p== NULL || q== NULL ) {
            return p == q;
        }
        
        if( p->val != q->val ) {
            return false;
        }
        
        return _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);
    }
};