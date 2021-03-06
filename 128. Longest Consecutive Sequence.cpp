// ***
//
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
// Your algorithm should run in O(n) complexity.
//
// Example:
//
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//
// ***
//
// This question: find the length of the longest consecutive elements (element order does NOT matter).
// See also 300. Longest Increasing Subsequence: find the longest increasing subseqeunce (element order DOES matter).

int longestConsecutive(vector<int>& nums) {
    // Convert vector to unordered_set to eliminate duplicate elements
    unordered_set<int> seen(nums.begin(), nums.end());
    int longest = 0;

    for (int num : nums) {
        // Find those that are greater than num
        int up = num + 1;
        while (seen.count(up)) {
            seen.erase(up);
            ++up;
        }

        // Find those that are less than num
        int down = num - 1;
        while (seen.count(down)) {
            seen.erase(down);
            --down;
        }

        longest = max(longest, up - down - 1);
    }

    return longest;
}
