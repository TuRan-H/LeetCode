#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int m = nums1.size(); // nums1 的长度
		int n = nums2.size(); // nums2 的长度

		// 确保 nums1 是较短的数组，以优化二分搜索的范围
		// 这意味着我们将在较小数组的分区上进行二分查找
		if (m > n) {
			std::swap(nums1, nums2); // 交换向量本身
			std::swap(m, n); // 交换它们的长度
		}

		int low = 0;
		int high = m; // partitionX 的二分搜索范围是 [0, m]

		// totalLeftElements 是合并后左侧分区应包含的元素总数
		// 这个公式能正确处理总长度为奇数和偶数时寻找中位数候选元素的情况
		int totalLeftElements = (m + n + 1) / 2;

		double median = 0.0; // 存储中位数的结果

		while (low <= high) {
			// partitionX 是 nums1 中位于左侧分区的元素数量
			// 也表示 nums1[0]...nums1[partitionX-1] 在左侧部分
			int partitionX = low + (high - low) / 2;

			// partitionY 是 nums2 中位于左侧分区的元素数量
			int partitionY = totalLeftElements - partitionX;

			// 确定四个边界元素:
			// maxLeftX: nums1 左侧分区的最大元素
			// minRightX: nums1 右侧分区的最小元素
			// maxLeftY: nums2 左侧分区的最大元素
			// minRightY: nums2 右侧分区的最小元素

			int maxLeftX = (partitionX == 0) ? std::numeric_limits<int>::min() : nums1[partitionX - 1];
			int minRightX = (partitionX == m) ? std::numeric_limits<int>::max() : nums1[partitionX];

			int maxLeftY = (partitionY == 0) ? std::numeric_limits<int>::min() : nums2[partitionY - 1];
			int minRightY = (partitionY == n) ? std::numeric_limits<int>::max() : nums2[partitionY];

			// 检查是否找到了正确的分区:
			// 所有左侧分区的元素必须小于等于所有右侧分区的元素
			if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
				// 找到了正确的分区，现在计算中位数
				if ((m + n) % 2 == 0) { // 元素总数为偶数
					// 中位数是两个中间元素的平均值：
					// 即合并后左侧部分的最大元素和右侧部分的最小元素
					median = (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
				} else { // 元素总数为奇数
					// 中位数是单个中间元素，即合并后左侧部分的最大元素
					median = static_cast<double>(std::max(maxLeftX, maxLeftY));
				}
				break; // 已找到中位数，退出循环
			} else if (maxLeftX > minRightY) {
				// maxLeftX 太大，需要将 partitionX 向左移动 (在 nums1 中)
				// 这会减少 nums1 左侧分区中的元素数量
				high = partitionX - 1;
			} else { // 这意味着 maxLeftY > minRightX
				// maxLeftY 太大 (或者 minRightX 太小)
				// 需要将 partitionX 向右移动 (在 nums1 中)
				// 这会增加 nums1 左侧分区中的元素数量，并减少 nums2 左侧分区中的元素数量
				low = partitionX + 1;
			}
		}
		return median; // 返回计算出的中位数
	}
};
// @lc code=end
