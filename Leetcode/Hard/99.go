/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 var(
    first *TreeNode
    second *TreeNode
    previous *TreeNode
)


func recoverTree(root *TreeNode)  {
    first, second, previous = nil, nil, nil
    
    inOrderTraversal(root)
    
    t := first.Val
    first.Val = second.Val
    second.Val = t
}

func inOrderTraversal(root *TreeNode) {
    if root == nil {
        return
    }
    
    inOrderTraversal(root.Left)
    
    if previous != nil && root.Val < previous.Val {
        if first == nil {
            first = previous
        }
        second = root
    }
    
    previous = root
    inOrderTraversal(root.Right)
}

