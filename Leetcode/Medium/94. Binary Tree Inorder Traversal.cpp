// https://leetcode.com/problems/binary-tree-inorder-traversal/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void inOrder(TreeNode* root, vector<int>& output){
        if(!root) return;
        inOrder(root->left, output);
        output.push_back(root->val);
        inOrder(root->right, output);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        inOrder(root, output);
        return output;
    }
};