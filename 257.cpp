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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> all_paths;
        // string path= "";
        // _binaryTreePaths(root, path, all_paths);
        
        if( root== NULL )
            return all_paths;
        
        stack<string> path_stack;
        stack<TreeNode*> node_stack;
        
        node_stack.push(root);
        path_stack.push(to_string(root->val));
        
        while( !node_stack.empty() ){
            TreeNode* curr= node_stack.top(); node_stack.pop();
            string path= path_stack.top(); path_stack.pop();
                
            if( !curr->left && !curr->right ) {
                all_paths.push_back(path);
            }
            
            if( curr->left ) {
                node_stack.push(curr->left);
                path_stack.push(path + "->" + to_string(curr->left->val));
            }
            
            if( curr->right ) {
                node_stack.push(curr->right);
                path_stack.push(path + "->" + to_string(curr->right->val));
            }
        }
        
        return all_paths;
    }
    
    void _binaryTreePaths(TreeNode* root, string path, vector<string>& all_paths ) {
        if( root== NULL )
            return;
        path+= path == "" ? to_string(root->val) : "->" + to_string(root->val);
        
        if( !root->left && !root->right ){
            all_paths.push_back(path);
            return;
        }
        
        _binaryTreePaths(root->left, path, all_paths);
        _binaryTreePaths(root->right, path, all_paths);
    }
};