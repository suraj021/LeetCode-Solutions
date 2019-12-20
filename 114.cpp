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
    void flatten(TreeNode* root) {
        TreeNode* pre= NULL;
        _flatten(root, pre);
    }
    
    void _flatten(TreeNode* root, TreeNode*& pre) {
        if( root== NULL )
            return;
        _flatten(root->right, pre);
        _flatten(root->left, pre);
        
        if( pre ) {
            root->right= pre;
            root->left= NULL;
        } 
        pre= root;
    }

    void __flatten(TreeNode *root) {
	    while (root) {
		    if (root->left && root->right) {
			TreeNode* t = root->left;
			while (t->right)
				t = t->right;
			t->right = root->right;
		}

        if(root->left)
		    root->right = root->left;
		root->left = NULL;
		root = root->right;
	}

};