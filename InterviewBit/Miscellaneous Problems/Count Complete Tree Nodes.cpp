/*
Given a complete binary tree, A, find the total number of nodes in the tree. 

Input Format:
The first and the only argument of input contains a reference to the root of the complete binary tree.

Output Format:
Return an integer representing the number of nodes in the complete binary tree.

Constraints:
1 <= Number of nodes in the binary tree <= 1e5

Examples:
Input 1:

        1
       / \
      2   3

Output 1:
    3

Input 2:

        1
       / \
      2   3
     / \
    4   5

Output 2:
    5

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int getHeight(TreeNode* root){
    if(!root) return 0;
    return 1 + getHeight(root->left);
}

bool isPresent(TreeNode* root, int num, int height){
    if(!root) return false;
    
    for(int i = height - 1; i > -1; i--){
        bool ck = num & (1 << i);
        if(!root) return false;
        if(ck){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return root != NULL;
}
int Solution::solve(TreeNode* A) {
    int height = getHeight(A) - 1;
    int ans = pow(2, height) - 1;
    
    int st =  0, ed = pow(2,height) - 1, mid, last_level_nodes = 0;
    
    while(st <= ed){
        mid = (st + ed) >> 1;
        bool flag = isPresent(A, mid, height);
        
        if(flag){
            last_level_nodes = mid;
            st = mid + 1;
        }
        else ed = mid - 1;
    }
    
    return ans + last_level_nodes + 1;
}
