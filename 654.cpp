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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return _constructMaximumBinaryTree(nums, 0, nums.size()-1);
    }
    
    TreeNode* _constructMaximumBinaryTree(vector<int>&nums, int start, int end){
        if(start > end) return NULL;
        int maxId= maxItemIndex(nums, start, end);
        TreeNode* root= new TreeNode(nums[maxId]);
        root->left= _constructMaximumBinaryTree(nums, start, maxId-1);
        root->right= _constructMaximumBinaryTree(nums, maxId+1, end);
        
        return root;
    }
    
    int maxItemIndex(vector<int>&nums, int start, int end){
        int maxSoFar= INT_MIN;
        int maxId;
        
        for(int i= start; i<= end; ++i){
            if(nums[i] > maxSoFar){
                maxSoFar= nums[i];
                maxId= i;
            }
        }
        
        return maxId;
    }
};