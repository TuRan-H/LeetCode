#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		int n = s.length(); // 获取字符串的长度
		if (n == 0) {
			return 0; // 如果字符串为空，最长子串长度为0
		}

		// lastIndex 数组用于存储每个字符最后一次出现的索引。
		// 假设字符集为扩展ASCII (0-255)，所以数组大小为256。
		// 初始化为 -1，表示字符尚未出现过。
		// 使用 static_cast<unsigned char> 是为了确保字符作为数组索引时是正值且在范围内。
		std::vector<int> lastIndex(256, -1);

		int maxLength = 0; // 用于存储找到的最长无重复字符子串的长度
		int left = 0; // 滑动窗口的左边界（包含）

		// right 是滑动窗口的右边界（包含）
		for (int right = 0; right < n; ++right) {
			char currentChar = s[right]; // 当前遍历到的字符

			// 检查当前字符 currentChar 是否在之前出现过 (lastIndex[...] != -1)
			// 并且其上一次出现的位置是否在当前窗口 [left, right-1] 之内 (lastIndex[...] >= left)
			if (lastIndex[static_cast<unsigned char>(currentChar)] != -1 && lastIndex[static_cast<unsigned char>(currentChar)] >= left) {
				// 如果是，说明 currentChar 在当前窗口内重复了。
				// 将左边界 left 移动到重复字符上一次出现位置的下一个位置。
				left = lastIndex[static_cast<unsigned char>(currentChar)] + 1;
			}

			// 更新当前字符 currentChar 最后一次出现的位置为当前 right 索引
			lastIndex[static_cast<unsigned char>(currentChar)] = right;

			// 计算当前有效窗口 [left...right] 的长度，并更新 maxLength
			// 当前窗口长度为 right - left + 1
			maxLength = std::max(maxLength, right - left + 1);
		}

		return maxLength; // 返回最长无重复字符子串的长度
	}
};
// @lc code=end
