/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    set<int> st;
    
    void fillTree(TreeNode* root){
        if(!root) return;
        st.insert(root->val);
        
        if(root->left) root->left->val = 2 * root->val + 1;
        if(root->right) root->right->val = 2 * root->val + 2;
        fillTree(root->left);
        fillTree(root->right);
    }
    
    FindElements(TreeNode* root) {
        st.clear();
        if(root != NULL) root->val = 0;
        fillTree(root);
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */