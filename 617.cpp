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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1== NULL) return t2;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({t1, t2});
        
        while(!q.empty()){
            pair<TreeNode*, TreeNode*> nodes= q.front();
            q.pop();
            
            if( nodes.second== NULL )
                continue;
            nodes.first->val+= nodes.second->val;
            
            if( nodes.first->left== NULL )
                nodes.first->left= nodes.second->left;
            else
                q.push({nodes.first->left, nodes.second->left});
            
            if( nodes.first->right== NULL )
                nodes.first->right= nodes.second->right;
            else
                q.push({nodes.first->right, nodes.second->right});
        }
        
        return t1;
    }
    
    TreeNode* _mergeTrees(TreeNode* t1, TreeNode* t2) {
        if( t1== NULL )
            return t2;
        if( t2== NULL )
            return t1;
        t1->val+= t2->val;
        t1->left= _mergeTrees(t1->left, t2->left);
        t1->right=_mergeTrees(t1->right, t2->right);
        
        return t1;
    }
};