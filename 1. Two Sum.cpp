// ***
//
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//
// ***

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;

    for (int i = 0; i < nums.size(); ++i) {
        int numberToFind = target - nums[i];

        if (hash.count(numberToFind)) {
            return {hash[numberToFind], i};
        }

        hash[nums[i]] = i;
    }

    return {0, 0};
}
