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
    int findTilt(TreeNode* root) {
        int tilt_sum= 0;
        _findTilt(root, tilt_sum);
        
        return tilt_sum;
    }
    
    int _findTilt(TreeNode* root, int& tilt_sum){
        if( root== NULL ) return 0;
        int l_tilt = _findTilt(root->left, tilt_sum);
        int r_tilt = _findTilt(root->right, tilt_sum);
        
        tilt_sum+= abs( l_tilt-r_tilt );
        
        return root->val+l_tilt+r_tilt;
    }
};