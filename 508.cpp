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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> freqSum;
        if(!root)   return freqSum;
        
        map<int, int> mapSum;
        subTreeSum(root, mapSum);
        
        int maxSumFreq= 0;
        for(auto sum: mapSum) {
            maxSumFreq= max(maxSumFreq, sum.second);
        }
        
        for(auto sum: mapSum) {
            if(sum.second == maxSumFreq){
                freqSum.push_back(sum.first);
            }
        }
        
        return freqSum;
    }
    
    int subTreeSum(TreeNode* root, map<int, int>& mapSum){
        if(!root) return 0;
        int nodeSum= root->val;
        nodeSum+= subTreeSum(root->left, mapSum);
        nodeSum+= subTreeSum(root->right, mapSum);
        mapSum[nodeSum]++;
        
        return nodeSum;
    }
};