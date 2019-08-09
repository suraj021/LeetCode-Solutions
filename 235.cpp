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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( p->val > q->val )
            swap(p, q);
        
        stack<TreeNode*> s;
        s.push(root);
        
        while( !s.empty() ){
            TreeNode* curr= s.top();
            s.pop();
            
            if( curr->val >= p->val && curr->val <= q->val )
                return curr;
            
            if( curr->val < p->val )
                s.push(curr->right);
            else
                s.push(curr->left);
        }
        
        return nullptr;
    }
    
    TreeNode* _lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( p->val > q->val )
            return lowestCommonAncestor(root, q, p);
        if( root->val >= p->val && root->val <= q->val )
            return root;
        else if( root->val > q->val )
            return lowestCommonAncestor(root->left, p, q);
        else 
            return lowestCommonAncestor(root->right, p, q);
    }
};