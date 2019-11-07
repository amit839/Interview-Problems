Problem : Two Sum BSTs

Given two binary search trees, return True if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.

 

Example 1:

    2                   1
  /   \               /   \
 1     4             0     3 

Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.

Example 2:

    0                   5
  /   \               /   \
-10    10            1     7 
                   /   \
                  0     2
                   
Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false


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
    
    void convertBst(TreeNode* root, vector<int> &output){
        if(!root) return;
        convertBst(root->left, output);
        output.push_back(root->val);
        convertBst(root->right, output);
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> arr1, arr2;
        convertBst(root1, arr1);
        convertBst(root2, arr2);
        
        int n = arr1.size(), m = arr2.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr1[i] + arr2[j] == target) return true;
            }
        }
        return false;
    }
};