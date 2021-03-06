// ***
//
// Given two arrays of length m and n with digits 0-9 representing two numbers.
// Create the maximum number of length k <= m + n from digits of the two.
// The relative order of the digits from the same array must be preserved. Return an array of the k digits.
// 
// Note: You should try to optimize your time and space complexity.
// 
// Example 1:
// 
// Input:
// nums1 = [3, 4, 6, 5]
// nums2 = [9, 1, 2, 5, 8, 3]
// k = 5
// Output:
// [9, 8, 6, 5, 3]
// 
// Example 2:
// 
// Input:
// nums1 = [6, 7]
// nums2 = [6, 0, 4]
// k = 5
// Output:
// [6, 7, 6, 0, 4]
// 
// Example 3:
// 
// Input:
// nums1 = [3, 9]
// nums2 = [8, 9]
// k = 3
// Output:
// [9, 8, 9]
//
// ***
//
// See http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-321-create-maximum-number/
// The problem logic is clear once you understand it. The problem can be devided into three sub-problems:
//
// 1. First maxNumber function:
// vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
//
// Given two arrays nums1 of length n1 and nums2 of length n2 and an integer k,
// if we want to get k <= n1 + n2 total elements from these two arrays,
// how many elements should we get from array1 and how many element should we get from array2?
// If we want to have k total number, we can get i numbers from nums1, and get k-i numbers from nums2.
//
// Example:
// nums1 = [4, 2, 8, 5]
// nums2 = [6, 5, 8]
// k = 5
// we can take 3 digits from nums1 and 2 digits from nums2
//
// 2. Second maxNumber function:
// vector<int> maxNumber(const vector<int>& nums, int k)
//
// How can we choose k elements from an array nums such that the number we get is largest
// and the order of idividual digit is preserved?
// After the first step, we are able to choose i numbers from nums1 and k-i numbers from nums2.
// Let's take nums1 for example: we want to know which i elements we should select from nums1
// such that the result is "largest" while preserving the order of digits in nums1? We do the same to nums2.
//
// Example:
// nums = [8, 9, 4, 2, 5]
// k = 3
// the "largest" 3-digit number we can choose while preserving the order of digits is [9, 4, 5] (i.e. 945)
//
// 3. Third maxNumber function:
// Given two arrays nums1 and nums2, combine them such that the result number is "largest"
// while preserving the order of digits in each individual array.
//
// Example:
// nums1 = [4, 9, 1]
// nums2 = [7, 2]
// combine them together, the "largest" number while preserving the order of digits in each individual array is [7, 4, 9, 2, 1]
//
class Solution
{

	public:

		vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
		{
			vector<int> res;
			int n1 = nums1.size();
			int n2 = nums2.size();

			// i = max(0, k-n2) because n2 might be smaller than k,
			// in which case we must select at least k-n2 elements from nums1;
			//
			// i <= min(n1, k) n1 might be smaller than k,
			// and we do not want i to be out of range of nums1
			// (in which case we must select the remaining k-n1 elements from nums2),
			// and we do not want i being larger than k (in which case we've selected all k elements from num1)
			for (int i = max(0, k-n2); i <= min(n1, k); ++i)
			{
				res = max(res, maxNumber(maxNumber(nums1, i), maxNumber(nums2, k-i)));
			}

			return res;
		}

	private:

		vector<int> maxNumber(const vector<int>& nums, int k)
		{
			// res is a stack, if you don't get this part see Huahua's note.
			// The basic idea is to keep our current "largest" in a stack.
			// When we are in the beginning of nums and see a large number (say 9),
			// we may pop everything we've seen before and only saves 9,
			// because you still have so many to add after 9.
			// However if you see 9 until very late in nums, you don't have any "pop quota" to pop elements,
			// therefore you may only pop 1 elements and add 9 to the end.
			vector<int> res;

			// Max number of elements that you are allowed to pop from the stack
			int popQuota = nums.size() - k;

			for (auto num : nums)
			{
				while (!res.empty() && num > res.back() && popQuota-- > 0)
				{
					// When you see a large number, you keep popping back existing elements
					// and move that large number to the beginning of your stack as long as you have the "pop quota".
					// For example you current largest is [3,5,1,6], your pop quota is 7. Now you see a 9,
					// your res will become [9] because your pop quota is 7 so you still have many things to add after 9.
					// However if your pop quota is 1, you might only replace the last element in your stack
					// and your res becomes [3,5,1,9].
					// If you make your res = [9], you have nothing left to be added after 9.
					res.pop_back();
				}

				res.push_back(num);
			}

			// we only need the first k elements
			res.resize(k);

			return res;
		}

		// Important to use const vector<int>& because you might be passing an rvalue std::vector<int>
		// to the function. A non-const vector<int>& cannot accept rvalue std::vector<int> or literal initialization,
		// and you will get an error: invalid initialization of non-const reference of type 'std::vector<int>&'
		// from an rvalue of type 'std::vector<int>'. As a rule of thumb, if you are calling functions inside functions,
		// you are likely to passing rvalues around, in which case it would be best to use const reference
		// as parameter so it can accept rvalue and literal arguments.
		vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2)
		{
			vector<int> res (nums1.size() + nums2.size());

			auto s1 = nums1.begin();
			auto e1 = nums1.end();

			auto s2 = nums2.begin();
			auto e2 = nums2.end();

			int index = 0;

			while(s1 != e1 || s2 != e2)
			{
				// Returns true if the range [s1, e1) compares lexicographically less than the range [s2, e2).
				// An empty vector is always less that a non-empty vector.
				// The template function is exactly the same as std::lexicographical_compare.
				res[index++] = lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++;
			}

			return res;
		}

		template <class ItrType1, class ItrType2>	
		bool lexicographical_compare(ItrType1 s1, ItrType1 e1, ItrType2 s2, ItrType2 e2)
		{
			while (s1 != e1)
			{
				if (s2 == e2)
				{
					return false;
				}
				else if (*s1 > *s2)
				{
					return false;
				}
				else if (*s1 < *s2)
				{
					return true;
				}
				else
				{
					++s1;
					++s2;
				}
			}

			return true;
		}

};
