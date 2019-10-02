// Link to the problem : https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int mod = 1e9 + 7;
long long int ans;

int power(int x, unsigned int y) { 
    int res = 1; 
    x = x % mod; 
    while (y > 0) { 
        if (y & 1) 
            res = (1LL*res*x) % mod; 
   
        y = y>>1; 
        x = (1LL*x*x) % mod;   
    } 
    return res; 
}

class Solution {
public:
    void helper(TreeNode* root, string val){
        if(root==NULL) return;
        val += to_string(root->val);
        if(root->left ==NULL and root->right ==NULL){
           
            long long int ival = 0, n = val.size();
            for(int i = 0;i<n;i++){
                if(val[i]=='1') {
                    ival = ((ival%mod) + (power(2,n-i-1)%mod))%mod;
                }
            }
            ans = ((ans% mod) + (ival%mod))%mod;;
            return;
        }
        helper(root->left,val);
        helper(root->right,val);
    }
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        helper(root,"");
        ans = (ans+mod)%mod;
        return ans;
    }
};