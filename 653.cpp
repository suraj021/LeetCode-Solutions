/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTiterator{
private:
    stack<TreeNode*> s;
    bool forward;
public:
    BSTiterator(TreeNode* root, bool fwd){
        forward= fwd;
        while(root) {
            s.push(root);
            root= forward ? root->left : root->right;
        }
    }
    
    bool hasNext() {
        return !s.empty();
    }
    
    int next() {
        TreeNode* node= s.top();
        s.pop();
        TreeNode* curr= forward ? node->right : node->left;
        
        while(curr){
            s.push(curr);
            curr= forward ? curr->left : curr->right;
        }
        
        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator fwd(root, true);
        BSTiterator bck(root, false);
        int l= fwd.next();
        int r= bck.next();
        while(l!=r) {
            if( l+r < k ){
                l= fwd.next();
            } else if( l+r > k ){
                r= bck.next();
            } else {
                return true;
            }
        }
        
        return false;
    }
};