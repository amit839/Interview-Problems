//  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    
    TreeNode* buildBST(int st, int ed, vector<int>& nums){
        if(st > ed) return NULL;
        
        int mid = (st + ed) >> 1;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(st, mid - 1, nums);
        root->right = buildBST(mid + 1, ed, nums);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return buildBST(0, n - 1, nums);
    }
};