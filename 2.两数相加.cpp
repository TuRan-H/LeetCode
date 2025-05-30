// @before-stub-for-debug-begin
#include "commoncppproblem2.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* dummyHead = new ListNode(0); // 虚拟头节点，简化链表构建过程
		ListNode* current = dummyHead; // 指向结果链表中当前最后一个节点的指针
		int carry = 0; // 初始化进位为0

		// 只要l1或l2中还有数字，或者还有进位，就继续循环
		while (l1 != nullptr || l2 != nullptr || carry != 0) {
			// 获取l1当前节点的值，如果l1已遍历完则为0
			int val1 = (l1 != nullptr) ? l1->val : 0;
			// 获取l2当前节点的值，如果l2已遍历完则为0
			int val2 = (l2 != nullptr) ? l2->val : 0;

			// 计算当前位的和
			int sum = val1 + val2 + carry;
			carry = sum / 10; // 更新进位供下一次迭代使用
			int digit = sum % 10; // 要存储在新节点中的数字

			// 用计算出的数字创建一个新节点，并将其附加到结果链表中
			current->next = new ListNode(digit);
			current = current->next; // 将当前指针移动到新节点

			// 如果l1中还有节点，则将其移至下一个节点
			if (l1 != nullptr) {
				l1 = l1->next;
			}
			// 如果l2中还有节点，则将其移至下一个节点
			if (l2 != nullptr) {
				l2 = l2->next;
			}
		}

		ListNode* resultHead = dummyHead->next; // 结果链表的实际头节点
		delete dummyHead; // 清理虚拟头节点（这是一个好习惯）

		return resultHead;
	}
};
// @lc code=end
