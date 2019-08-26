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
    TreeNode* _deleteNode(TreeNode* root) {
        if(!root->left && !root->right) {
            delete root;
            root= nullptr;
        } else if(!root->left){
            TreeNode* temp= root;
            root= root->right;
            delete temp;
        } else if(!root->right) {
            TreeNode* temp= root;
            root= root->left;
            delete temp;
        } else {
            TreeNode* inSucc= root->right;
            TreeNode* pre= NULL;
            while(inSucc->left){
                pre= inSucc;
                inSucc= inSucc->left;
            }
            inSucc->left= root->left;
            if(root->right!= inSucc) {
                pre->left= inSucc->right;
                inSucc->right= root->right;
            }
            delete root;
            root= nullptr;
            return inSucc;
        }
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        TreeNode* pre= NULL;
        TreeNode* curr= root;
        
        while(curr && curr->val!= key) {
            pre= curr;
            if(key < curr->val)
                curr= curr->left;
            else
                curr= curr->right;
        }
        
        if(!curr){
            return root;
        }
        
        if(!pre)
            root= _deleteNode(curr);
        else if( pre->left== curr )
            pre->left= _deleteNode(curr);
        else
            pre->right= _deleteNode(curr);
        
        return root;
    }
    
    TreeNode* _deleteNodeRecursive(TreeNode* root, int key) {
        if(!root)   return nullptr;
        
        if( root->val < key ) {
            root->right= _deleteNodeRecursive(root->right, key);
        } else if ( root->val > key ) {
            root->left= _deleteNodeRecursive(root->left, key);
        } else {
            if(!root->left && !root->right) {
                delete root;
                root= nullptr;
            } else if(!root->left) {
                TreeNode* temp= root;
                root= root->right;
                delete temp;
            } else if(!root->right) {
                TreeNode* temp= root;
                root= root->left;
                delete temp;
            } else {
                TreeNode* inSucc= minNode(root->right);
                root->val= inSucc->val;
                root->right= _deleteNodeRecursive(root->right, root->val);
            }
        }
        
        return root;
    }
    
    TreeNode* minNode(TreeNode* root) {
        while(root->left)
            root= root->left;
        return root;
    }
};