// ***
//
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// 
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// 
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).
// 
// Example 1:
// 
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:
// 
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//
// ***
//
// Altough you do not know where the pivot point is, either left half or right half of the array must be sorted.
//
// TODO: Verify if below is true:
//
// For these kinds of binary search questions which
//
// 1. You need to take the index of left and right i.e. left and right serve as indexes, not bounds: nums[left], nums[right]
// -> Then you must initialize left = 0 and right = nums.size() - 1 (not nums.size()), because you can't take index on nums when i = nums.size(),
//
// 2. You are finding an element which might not be in the array (which you need to return -1)
// -> Then the condition should be while (left <= right), because otherwise if nums has size 1 then the while loop will simply not execute.
//
// In all these cases, you can set right = mid instead of right = mid - 1 (In 33. and 81., set right = mid or right = mid - 1 will all pass the OJ)
int search(vector<int>& nums, int target)
{
	int left = 0, right = nums.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
		{
			return mid;
		}
		// Right half is sorted.
		else if (nums[mid] < nums[right])
		{
			// Target is in this sorted right half of the array.
			if (nums[mid] < target && target <= nums[right])
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		// Left half is sorted.
		else
		{
			// Target is in this sorted left half of the array.
			if (nums[left] <= target && nums[mid] > target)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
	}

	return -1;
}