// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    
    int getHeight(TreeNode* root, map<TreeNode*,int> &mp){
        if(!root) return 0;
        int left = getHeight(root->left, mp);
        int right = getHeight(root->right, mp);
        
        mp[root] = left + right + 1;
        return left + right + 1;
    }
    
    int findElement(TreeNode* root, int k, map<TreeNode*,int>& mp){
        if(!root) return -1;
        
        if(k <= mp[root->left]) return findElement(root->left, k, mp);
        if(k == mp[root->left] + 1) return root->val;
        
        return findElement(root->right, k - mp[root->left] - 1, mp);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        map<TreeNode*, int> mp;
        
        getHeight(root, mp);
        
        return findElement(root, k, mp);
    }
};