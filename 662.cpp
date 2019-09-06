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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 1});
        unsigned int maxDiameter= 0;
        
        while(!q.empty()){
            int lvl_sz= q.size();
            unsigned int l= q.front().second;
            unsigned int r;
            for( int i= 0; i< lvl_sz; ++i ) {
                pair<TreeNode*, unsigned int> curr= q.front(); q.pop();
                r= curr.second;
                if(curr.first->left) q.push({curr.first->left, 2*r});
                if(curr.first->right) q.push({curr.first->right, 2*r+1});
            }
            maxDiameter= max(maxDiameter, r-l+1);
        }
        
        return maxDiameter;
    }
};