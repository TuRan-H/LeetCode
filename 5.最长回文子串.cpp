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
	// 辅助函数：以潜在中心点扩展并更新找到的最长回文串
	// 通过引用传递 `current_max_start` 和 `current_max_len` 来直接更新它们
	void expandAndCheck(const std::string& s, int left_candidate, int right_candidate,
		int& current_max_start, int& current_max_len)
	{
		int l = left_candidate;
		int r = right_candidate;

		// 当字符匹配且指针在边界内时继续扩展
		while (l >= 0 && r < s.length() && s[l] == s[r]) {
			l--;
			r++;
		}

		// 循环结束后，实际的回文串是 s[l+1 ... r-1]
		// 它的长度是 (r-1) - (l+1) + 1 = r - l - 1
		int current_palindrome_len = r - l - 1;

		if (current_palindrome_len > current_max_len) {
			current_max_len = current_palindrome_len;
			current_max_start = l + 1; // 这个新的最长回文串的起始索引
		}
	}

	std::string longestPalindrome(std::string s)
	{
		if (s.length() < 1) { // 或者使用 s.empty()
			return "";
		}

		int res_start_idx = 0; // 找到的最长回文串的起始索引
		int res_max_len = 1; // 找到的最长回文串的长度（单个字符的最小长度为1）

		for (int i = 0; i < s.length(); ++i) {
			// 情况1：奇数长度回文串
			// 中心是字符 s[i]
			expandAndCheck(s, i, i, res_start_idx, res_max_len);

			// 情况2：偶数长度回文串
			// 中心在 s[i] 和 s[i+1] 之间
			// expandAndCheck 辅助函数很健壮：如果 i+1 超出边界，
			// while 循环条件 (r < s.length()) 会正确处理
			expandAndCheck(s, i, i + 1, res_start_idx, res_max_len);
		}

		return s.substr(res_start_idx, res_max_len);
	}
};
// @lc code=end
