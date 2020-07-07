// ***
//
// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// ***
//
// See also 106. Construct Binary Tree from Inorder and Postorder Traversal.
// These two are basically the same question.
//
// Preorder [root  (left subtree)  (right subtree)]
// Inorder  [(left subtree)  root  (right subtree)]
//
// Preorder traversing implies that preorder[0] is the root node.
// Then we can find this preorder[0] in inorder, say it's inorder[5].
// Now we know that inorder[5] is root, so we know that inorder[0] to inorder[4] is its left subtress, inorder[6] to the
// end is its right subtree. Recursively doing this on subarrays, we can build a tree from it.

class Solution {
public:
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        int preorderLeft = 0, preorderRight = preorder.size();
        int inorderLeft = 0, inorderRight = inorder.size();

        return _buildTree(preorder, preorderLeft, preorderRight, inorder, inorderLeft, inorderRight);
    }

private:
    TreeNode* _buildTree(const vector<int>& preorder, int preorderLeft, int preorderRight, const vector<int>& inorder,
                         int inorderLeft, int inorderRight) {
        if (preorderLeft >= preorderRight || inorderLeft >= inorderRight) {
            return nullptr;
        }

        int rootValue = preorder[preorderLeft];

        auto itr = find(inorder.begin() + inorderLeft, inorder.begin() + inorderRight, rootValue);
        int leftSubtreeSize = itr - inorder.begin() - inorderLeft;

        TreeNode* root = new TreeNode(rootValue);
        root->left = _buildTree(preorder, preorderLeft + 1, preorderLeft + 1 + leftSubtreeSize, inorder, inorderLeft,
                                inorderLeft + leftSubtreeSize);
        root->right = _buildTree(preorder, preorderLeft + 1 + leftSubtreeSize, preorderRight, inorder,
                                 inorderLeft + leftSubtreeSize + 1, inorderRight);

        return root;
    }
};
