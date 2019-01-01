// ***
//
// You are given a binary tree in which each node contains an integer value.
// Find the number of paths that sum to a given value.
// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
// 
// Example:
// 
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
// 
//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1
// 
// Return 3. The paths that sum to 8 are:
// 
// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11
//
// ***
//
// Two recursion. One to iterate all subtree in a tree, i.e. treat each node as the root,
// the other recursion counts the sum in that tree.
// Clear but not the most efficient one.
class Solution
{

	public:

		int pathSum(TreeNode* root, int sum)
		{
			if (!root)
			{
				return 0;
			}

			return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
		}

	private:

		int dfs(TreeNode* node, int sum)
		{
			int count = 0;

			if (!node)
			{
				return 0;
			}

			if (node->val == sum)
			{
				++count;
			}

			count += dfs(node->left, sum - node->val) + dfs(node->right, sum - node->val);

			return count;
		}

};

// Same idea.
class Solution
{

	public:

		int pathSum(TreeNode* root, int sum)
		{
			if (!root)
			{
				return 0;
			}

			dfs(root, sum);
			pathSum(root->left, sum);
			pathSum(root->right, sum);

			return total;
		}

	private:

		int total = 0;

		void dfs(TreeNode* node, int sum)
		{
			if (!node)
			{
				return;
			}

			if (node->val == sum)
			{
				++total;
			}

			dfs(node->left, sum - node->val);
			dfs(node->right, sum - node->val);
		}

};

