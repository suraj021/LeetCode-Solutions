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
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        if(!root) return modes;
        
        int count= 0, maxFreq= 0;
        TreeNode* pre= NULL;
        setMaxFreq(root, pre, count, maxFreq);
        
        pre= NULL;
        count= 0;
        setModes(root, pre, count, maxFreq, modes);
        
        return modes;
    }
    
    // support code for the O(1)
    void setMaxFreq(TreeNode* root, TreeNode*& pre, int &count, int& maxFreq){
        if(!root) return;
        setMaxFreq(root->left, pre, count, maxFreq);
        
        if( pre && pre->val== root->val)
            count++;
        else
            count= 1;
        maxFreq= max(maxFreq, count);
        pre= root;
        
        setMaxFreq(root->right, pre, count, maxFreq);
    }
    
    void setModes(TreeNode* root, TreeNode*& pre, int& count, int maxFreq, vector<int>& modes){
        if(!root) return;
        
        setModes(root->left, pre, count, maxFreq, modes);
        if( pre && pre->val== root->val){
            count++;
        } else{
            count= 1;
        }
        if( count== maxFreq ) {
            modes.push_back(root->val);
        }
        pre= root;
        setModes(root->right, pre, count, maxFreq, modes);
    }
    
    // suppport code for O(n)
    vector<int> findModeIterative(TreeNode* root){
        vector<int> modes;
        if(!root) return modes;
        
        map<int, int> freq;
        setFreq(root, freq);
        
        int maxFreq= 0;
        for(auto node: freq) {
            maxFreq= max(maxFreq, node.second);
        }
        
        for(auto node: freq) {
            if(node.second == maxFreq){
                modes.push_back(node.first);
            }
        }
        
        return modes;
    }
        
    void setFreq(TreeNode* root, map<int, int>& freq){
        if(!root) return;
        setFreq(root->left, freq);
        setFreq(root->right, freq);
        freq[root->val]++;
    }
};