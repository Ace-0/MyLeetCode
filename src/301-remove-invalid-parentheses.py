# 301. Remove Invalid Parentheses


class Solution:
    def removeInvalidParentheses(self, s: str) -> list:
        left_num = 0  # max number of '(' to remove
        right_num = 0  # max number of ')' to remove
        for ch in s:
            if ch == '(':
                left_num += 1
            elif ch == ')':
                if left_num:
                    left_num -= 1
                else:
                    right_num += 1
        res = set()
        self.dfs(left_num, right_num, 0, '', 0, s, res)
        return list(res)

    def dfs(self, left_num, right_num, open, path, i, s, res):
        if left_num < 0 or right_num < 0 or open < 0:
            return
        elif i == len(s):
            if left_num == 0 and right_num == 0 and open == 0:
                res.add(path)
        else:
            ch = s[i]
            if ch == '(':
                # add
                self.dfs(left_num, right_num, open + 1, path + ch, i + 1, s, res)
                # skip
                self.dfs(left_num - 1, right_num, open, path, i + 1, s, res)
            elif ch == ')':
                # add
                self.dfs(left_num, right_num, open - 1, path + ch, i + 1, s, res)
                # skip
                self.dfs(left_num, right_num - 1, open, path, i + 1, s, res)
            else:
                # add s[i]
                self.dfs(left_num, right_num, open, path + ch, i + 1, s, res)


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = '()())()'

    ans = s.removeInvalidParentheses(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))