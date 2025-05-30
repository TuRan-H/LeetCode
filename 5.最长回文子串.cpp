#include <string>
using namespace std;

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
	// Helper function to expand around a potential center and update the longest palindrome found
	// It takes references to `current_max_start` and `current_max_len` to update them directly.
	void expandAndCheck(const std::string& s, int left_candidate, int right_candidate,
		int& current_max_start, int& current_max_len)
	{
		int l = left_candidate;
		int r = right_candidate;

		// Expand while characters match and pointers are within bounds
		while (l >= 0 && r < s.length() && s[l] == s[r]) {
			l--;
			r++;
		}

		// After the loop, the actual palindrome is s[l+1 ... r-1]
		// Its length is (r-1) - (l+1) + 1 = r - l - 1
		int current_palindrome_len = r - l - 1;

		if (current_palindrome_len > current_max_len) {
			current_max_len = current_palindrome_len;
			current_max_start = l + 1; // Starting index of this new longest palindrome
		}
	}

	std::string longestPalindrome(std::string s)
	{
		if (s.length() < 1) { // Or s.empty()
			return "";
		}

		int res_start_idx = 0; // Start index of the longest palindrome found
		int res_max_len = 1; // Length of the longest palindrome found (min length is 1 for a single char)

		for (int i = 0; i < s.length(); ++i) {
			// Case 1: Odd length palindromes
			// Center is the character s[i]
			expandAndCheck(s, i, i, res_start_idx, res_max_len);

			// Case 2: Even length palindromes
			// Center is between s[i] and s[i+1]
			// The expandAndCheck helper is robust: if i+1 is out of bounds,
			// the while loop condition (r < s.length()) will handle it correctly.
			expandAndCheck(s, i, i + 1, res_start_idx, res_max_len);
		}

		return s.substr(res_start_idx, res_max_len);
	}
};
// @lc code=end
