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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> kNodes;
        if(!root) return kNodes;
        
        map<TreeNode*, TreeNode*> parent;
        fillParentNodes(root, root, parent);
        fillKdistanceNode(target, K, kNodes, parent);

        return kNodes;
    }
    
    void fillParentNodes(TreeNode* root, TreeNode* pre, map<TreeNode*, TreeNode*>& parent){
        if(!root) return;
        parent[root]= pre;
        fillParentNodes(root->left, root, parent);
        fillParentNodes(root->right, root, parent);
    }
    
    void fillKdistanceNode(TreeNode* root, int k, vector<int>& kNodes, map<TreeNode*, TreeNode*> parent) {
        if(!root) return;
        
        map<TreeNode*, bool> seen;
        queue<TreeNode*> q;
        q.push(root);
        
        for(int i= 0; i< k || !q.empty(); ++i){
            int lvl_size= q.size();
            for(int j= 0; j< lvl_size; ++j){
                TreeNode* node= q.front(); q.pop();
                seen[node]= true;
                if(node->left && !seen[node->left])  q.push(node->left);
                if(node->right && !seen[node->right]) q.push(node->right);
                if(parent[node] != node && !seen[parent[node]]) q.push(parent[node]);
                if(i== k){
                    kNodes.push_back(node->val);
                }
            }
        }
    }
};