//  https://leetcode.com/problems/validate-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *previous;
class Solution {
public:

    bool checkBST(TreeNode* root){
        if(!root) return true;

        bool lans = checkBST(root->left);
        if(!lans) return false;

        if(previous != NULL and root->val <= previous->val) return false;
        previous = root;
        return checkBST(root->right);
    }


    bool isValidBST(TreeNode* root) {
        previous = NULL;
        return checkBST(root);
    }
};