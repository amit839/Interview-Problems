// Link to the problem: https://leetcode.com/problems/leaf-similar-trees/
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
    
    void getAllRoot(TreeNode* root, vector<int> &ar){
        if(root==NULL) return;
        if(root->left == NULL and root->right == NULL) ar.push_back(root->val);
        getAllRoot(root->left,ar);
        getAllRoot(root->right,ar);
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       vector<int> arr,brr;
        
        getAllRoot(root1,arr);
        getAllRoot(root2,brr);
        
        if(arr.size()!=brr.size()) return false;
        for(int i = 0; i< arr.size();i++){
            if(arr[i]!=brr[i]) return false;
        }
        return true;
    }
    
};