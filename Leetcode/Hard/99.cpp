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
    
    TreeNode *first, *second, *previous;
    
    void inOrder(TreeNode* root){
        if(!root) return;
        
        inOrder(root->left);
        
        if(previous != NULL and root->val < previous->val){
            if(first == NULL){
                first = previous;
            }
            second = root;
        }
        
        previous = root;
        inOrder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        first = second = previous = NULL;
        inOrder(root);
        swap(first->val, second->val);
    }
};