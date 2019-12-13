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
    int findBottomLeftValue(TreeNode* root) {        
        queue<TreeNode*> q;
        q.push(root);
        int leftmost= INT_MIN;
        
        while(!q.empty()){
            int sz= q.size();
            int maxVal= INT_MIN;
            for(int i= 0; i< sz; ++i) {
                TreeNode* node= q.front();
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
                if(i== 0)
                    leftmost= node->val;
            }
            
        }
        
        return leftmost;
    }
};