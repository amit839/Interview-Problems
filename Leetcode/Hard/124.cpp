// link to the problem statement : https://leetcode.com/problems/binary-tree-maximum-path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int ans;

class Solution {
public:
    int findMaxPath(TreeNode* root){
		if(!root) return 0;
		
		int left = findMaxPath(root->left);
		int right = findMaxPath(root->right);
		
		// updating our global answer using current node
		ans = max({ans, root->val , root->val + left, root->val + right, root->val + left + right});
		
		return max({root->val, root->val + left, root->val + right});
    }
	
    int maxPathSum(TreeNode* root) {
        ans = INT32_MIN;
        findMaxPath(root);	
        return ans;
    }

};