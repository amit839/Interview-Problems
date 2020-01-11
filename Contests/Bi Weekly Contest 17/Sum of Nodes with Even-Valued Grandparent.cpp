// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int ans;
    
    void traverse(TreeNode* root){
        if(!root) return;
        
        if(root->val % 2 == 0){
            if(root->left){
                if(root->left->left) ans += root->left->left->val;
                if(root->left->right) ans += root->left->right->val;
            }
            if(root->right){
                if(root->right->left) ans += root->right->left->val;
                if(root->right->right) ans += root->right->right->val;
            }
        }
        traverse(root->left);
        traverse(root->right);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        ans = 0;
        traverse(root);
        return ans;
    }
};