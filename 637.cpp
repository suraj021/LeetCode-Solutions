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
    vector<double> averageOfLevels(TreeNode* root) {        
        queue<TreeNode*> q;
        vector<double> avg;
        
        if( root== NULL ) return avg;

        q.push(root);
        
        while(!q.empty()){
            double sum= 0;
            int lvl_size= q.size();
            for( int i= 0; i< lvl_size; ++i ){
                TreeNode* node= q.front(); q.pop();
                sum+= double(node->val);
                if( node->left ) q.push(node->left);
                if( node->right ) q.push(node->right);
            }
            
            avg.push_back(1.0*sum/lvl_size);
        }
        
        return avg;
    }
};