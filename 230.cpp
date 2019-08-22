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
    int kthSmallest(TreeNode* root, int& k) {
//         stack<TreeNode*> s;
//         TreeNode* curr= root;
//         int n= 0;
        
//         while(curr || !s.empty()){
//             while(curr){
//                 s.push(curr);
//                 curr= curr->left;
//             }
            
//             curr= s.top(); s.pop();
//             n++;
            
//             if( n== k )
//                 return curr->val;
            
//             curr= curr->right;
//         }
        return _kthSmallest(root, k);
    }

    int _kthSmallest(TreeNode* root, int& k){
        if(!root) return INT_MIN;
        
        int left= _kthSmallest(root->left, k);
        
        if( left != INT_MIN )   return left;
        
        if( --k== 0 )   return root->val;
        
        return _kthSmallest(root->right, k);
    }
};