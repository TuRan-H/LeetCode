#
# @lc app=leetcode.cn id=10 lang=python3
#
# [10] 正则表达式匹配
#

# @lc code=start
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        D = [[0] * (len(p) + 1) for _ in range(len(s) + 1)]
        D[0][0] = 1

        for j in range(1, len(p) + 1):
            if p[j - 1] != "*": D[0][j] = 0
            else: D[0][j] = D[0][j - 2]


        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                if p[j - 1] != "*":
                    D[i][j] = int(D[i - 1][j - 1] and (s[i - 1] == p[j - 1] or "." in [s[i - 1], p[j - 1]]))
                elif p[j - 1] == "*":
                    D[i][j] = int(D[i][j - 2] or D[i - 1][j] and (s[i - 1] == p[j - 2] or "." in [s[i - 1], p[j - 2]]))
        
        return bool(D[-1][-1])
        
# @lc code=end

