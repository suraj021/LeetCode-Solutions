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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lo;
        
        if( root == NULL ){
            return lo;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> levelVal;
            queue<TreeNode*> levelq;
            
            while( !q.empty() ){
                TreeNode* n = q.front();
                q.pop();
                levelVal.push_back(n->val);
                if( n->left ){
                    levelq.push(n->left);
                }
                if( n->right ) {
                    levelq.push(n->right);
                }
            }
            
            lo.push_back(levelVal);
            q= levelq;
        }
        
        return lo;
    }
};