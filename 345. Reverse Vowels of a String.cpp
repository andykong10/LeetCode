// ***
//
// Write a function that takes a string as input and reverse only the vowels of a string.
//
// Example 1:
//
// Input: "hello"
// Output: "holle"
//
// Example 2:
//
// Input: "leetcode"
// Output: "leotcede"
//
// ***

string reverseVowels(string s) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
        if (!vowels.count(s[i])) {
            ++i;
        }

        if (!vowels.count(s[j])) {
            --j;
        }

        if (vowels.count(s[i]) && vowels.count(s[j])) {
            swap(s[i++], s[j--]);
        }
    }

    return s;
}
