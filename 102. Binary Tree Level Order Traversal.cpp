// Our DFS solution uses preorder traversal to take care of current node first then its subtrees,
// using preorder might be a bit more intuitive, but actually in the DFS solution for this question,
// it doesn't matter if you use preorder, inorder, or postorder traversal.
//
// Compare this question with 366. Find Leaves of Binary Tree, which is a very similar question
// but uses a bottom up approach.
class Solution
{

	public:

		vector<vector<int>> levelOrder(TreeNode* root)
		{
			int level = 0;
			dfs(root, level);
			return mResult;
		}

	private:

		vector<vector<int>> mResult;

		void dfs(TreeNode* root, int level)
		{
			if (!root)
			{
				return;
			}

			while (mResult.size() <= level)	
			{
				mResult.push_back({});
			}

			mResult[level].push_back(root->val);

			dfs(root->left, level + 1);
			dfs(root->right, level + 1);
		}

};

// BFS solution:
vector<vector<int>> levelOrder(TreeNode* root)
{
	if (!root)
	{
		return {};
	}

	vector<vector<int>> result;

	vector<TreeNode*> currentLevel = {root};
	vector<TreeNode*> nextLevel = {};

	while (!currentLevel.empty())
	{
		result.push_back({});

		for (auto node : currentLevel)	
		{
			result.back().push_back(node->val);

			if (node->left)
			{
				nextLevel.push_back(node->left);
			}
			if (node->right)
			{
				nextLevel.push_back(node->right);
			}
		}

		currentLevel.swap(nextLevel);
		nextLevel.clear();
	}

	return result;
}