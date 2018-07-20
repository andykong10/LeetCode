class Solution {
public:
    // Using unordered_set. The basic idea is to maintain a set s which contain unique values from nums[i - k] to nums[i - 1], if nums[i] is in set s then return true, else update the set.
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> seen; // a sliding window of last k elements

        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)
                seen.erase(nums[i-k-1]);
            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }
            seen.insert(nums[i]);
        }

        return false;

    }

    // using unordered_map
    bool containsNearbyDuplicate2(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (seen.find(nums[i]) != seen.end()) {
                if (i - seen[nums[i]] <= k)
                    return true;
            }
            seen[nums[i]] = i;
        }
        return false;
    }
};
