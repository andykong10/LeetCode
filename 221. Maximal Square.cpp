// ***
//
// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
// Example:
// 
// Input: 
// 
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// 
// Output: 4 at (i, j).
//
// ***
//
// dp[i][j] the longest edge of the square which bottom right corner isGiven a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
int maximalSquare(vector<vector<char>>& matrix)
{
	// No need to check if matrix[0] is empty because [['1']] is valid.
	if (matrix.empty())
	{
		return 0;
	}

	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> dp(m, vector<int>(n));

	int longestEdge = 0;

	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = matrix[i][j] - '0';
			}
			else if (matrix[i][j] == '1')
			{
				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
			}

			longestEdge = max(longestEdge, dp[i][j]);
		}
	}

	return pow(longestEdge, 2);
}