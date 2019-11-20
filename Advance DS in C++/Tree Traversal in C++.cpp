#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    
    // Function to earse all the nodes from memory
    void freeMemory(TreeNode *root){
        if(!root) return;
        freeMemory(root->left);
        freeMemory(root->right);
        cout << "Erasing node with value -> "<< root->val <<'\n';
        delete root;
    }

};

// Building a balanced tree(Log(N) height) from a vector
TreeNode* buildTree(int i, int j, vector<int>& input){
    if(i > j) return nullptr;
    if(i == j) return new TreeNode(input[i]);

    int mid = (i + j) >> 1;
    TreeNode *root = new TreeNode(input[mid]);
    root->left = buildTree(i, mid - 1, input);
    root->right = buildTree(mid + 1, j, input);

    return root;
}

// PreOrder Traversal of a Binary Tree( print root, then print the left subtree, then right subtree)
void preOrderTraversal(TreeNode* root){
    if(!root) return;
    cout << root->val << ' ';
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


// InOrder Traversal of a Binary Tree( print the left subtree, print root, then right subtree)
void inOrderTraversal(TreeNode* root){
    if(!root) return;
    inOrderTraversal(root->left);
    cout << root->val << ' ';
    inOrderTraversal(root->right);
}


// PostOrder Traversal of a Binary Tree( print the left subtree, then right subtree and then root)
void postOrderTraversal(TreeNode* root){
    if(!root) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << ' ';
}


void testcase(){
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};
    
    TreeNode *root = buildTree(0, input.size() - 1, input); 
    
    preOrderTraversal(root);
    cout << '\n';
    
    inOrderTraversal(root);
    cout <<'\n';
    
    postOrderTraversal(root);
    cout << '\n';

    root->freeMemory(root);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

#ifdef AKP
    freopen("in.txt", "r", stdin);
#endif

    int t = 1;
    //cin >> t;
    while(t--){
        testcase();
    }
}