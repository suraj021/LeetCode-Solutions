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
    vector<int> largestValues(TreeNode* root) {
        vector<int> large;
        if(!root) return large;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz= q.size();
            int maxVal= INT_MIN;
            for(int i= 0; i< sz; ++i) {
                TreeNode* node= q.front();
                q.pop();
                maxVal= max(maxVal, node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            large.push_back(maxVal);
        }
        
        return large;
    }
};