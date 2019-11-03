/*
Given a binary tree T, find the maximum path sum. The path may start and end at any node in the tree. Input Format:
The first and the only argument contains a pointer to the root of T, A.

Output Format:
Return an integer representing the maximum sum path.
Constraints:

1 <= Number of Nodes <= 7e4
-1000 <= Value of Node in T <= 1000

Example :
Input 1:

       1
      / \
     2   3

Output 1:
     6

Explanation 1:
    The path with maximum sum is: 2 -> 1 -> 3

Input 2:

       -10
       /  \
     -20  -30

Output 2:
    -10

Explanation 2
    The path with maximum sum is: -10

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

int ans;
 
int findMaxPath(TreeNode* root){
    if(!root) return 0;
    
    int left = findMaxPath(root->left);
    int right = findMaxPath(root->right);
    
    ans = max({ans, root->val, root->val + left, root->val + right, root->val + left + right});
    
    return max({root->val, root->val + left, root->val + right});
}
 
int Solution::maxPathSum(TreeNode* A) {
    ans = INT_MIN;
    findMaxPath(A);
    return ans;
}
