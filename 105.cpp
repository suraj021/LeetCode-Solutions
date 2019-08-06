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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if( preorder.size() == 0 )
            return NULL;
        
        map<int, int> inmap;
        for( int i= 0; i< inorder.size(); ++i ) {
            inmap[inorder[i]]= i;
        }
        TreeNode* root= new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        
        s.push(root);
        
        for( int i= 1; i< preorder.size(); ++i ) {
            TreeNode* node = new TreeNode(preorder[i]);
            if( inmap[node->val] < inmap[s.top()->val]){
                s.top()->left= node;
            } else {
                TreeNode* p;
                while( !s.empty() && inmap[node->val] > inmap[s.top()->val] ){
                    p= s.top();
                    s.pop();
                }
                p->right= node;
            }
            
            s.push(node);
        }
        
        return root;
    }
    
    TreeNode* build(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if( preStart > preorder.size()-1 || inStart > inEnd ) {
            return NULL;
        }
        
        TreeNode* root= new TreeNode(preorder[preStart]);
        int index= 0;
        
        for( int i= inStart; i<= inEnd; ++i ) {
            if( inorder[i] == root->val ){
                index= i;
                // break;
            }
        }
        
        root->left= build(preStart+1, inStart, index-1, preorder, inorder);
        root->left= build(preStart+index-inStart+1, index+1, inEnd, preorder, inorder);
        
        return root;
    }
};