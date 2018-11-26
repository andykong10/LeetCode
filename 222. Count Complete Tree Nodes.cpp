// We are already told that the tree is complete, so if there's any difference in height,
// then there's at most one. We traverse all the way to the left node, and traverse all the way to the 
// right node, and see the difference in height. If same, then it is a perfect tree, return 2^height-1.
// Otherwise, recursively traverse the left and right subtrees.
int countNodes(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}

	TreeNode *pLeft = root, *pRight = root;
	int heightLeft = 0, heightRight = 0;

	while (pLeft)
	{
		++heightLeft;
		pLeft = pLeft->left;
	}

	while (pRight)
	{
		++heightRight;
		pRight = pRight->right;
	}

	if (heightLeft == heightRight)
	{
		return pow(2, heightLeft) - 1;
	}

	return 1 + countNodes(root->left) + countNodes(root->right);
}

// Same idea.
class Solution
{

	public:

		int countNodes(TreeNode* root)
		{
			int hLeft = leftHeight(root);
			int hRight = rightHeight(root);

			if (hLeft == hRight)
			{
				return pow(2, hLeft) - 1;
			}

			return 1 + countNodes(root->left) + countNodes(root->right);
		}
	
	private:

		int leftHeight(TreeNode* root)
		{
			if (!root)
			{
				return 0;
			}

			return 1 + leftHeight(root->left);
		}

		int rightHeight(TreeNode* root)
		{
			if (!root)
			{
				return 0;
			}

			return 1 + rightHeight(root->right);
		}

};