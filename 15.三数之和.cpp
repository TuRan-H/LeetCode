// @before-stub-for-debug-begin
#include "commoncppproblem15.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

#include <algorithm>
#include <set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		set<vector<int>> triples = {};

		// 逐条遍历 i, j, k
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				// if (nums[j] == nums[i])
				// 	continue;
				for (int k = j + 1; k < nums.size(); ++k) {
					// if (nums[k] == nums[j])
					// 	continue;
					if (nums[i] + nums[j] + nums[k] == 0) {
						vector<int> triple = { nums[i], nums[j], nums[k] };
						// 将triple进行排序, 添加到triples集合中
						sort(triple.begin(), triple.end());
						triples.insert(triple);
					}
				}
			}
		}

		// 将triples转化为 vector<vector<int>> 类型
		return vector<vector<int>>(triples.begin(), triples.end());
	}
};
// @lc code=end
