# 46. Permutations

class Solution:
    def permute(self, nums: 'List[int]') -> 'List[List[int]]':
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        all_perm = []
        visited = [False] * len(nums)
        cur_perm = []
        self.dfs(cur_perm, visited, nums, all_perm)

        return all_perm

    def dfs(self, cur_perm, visited, nums, all_perm):
        is_end = True
        for i in range(0, len(nums)):
            if not visited[i]:
                is_end = False
                cur_perm.append(nums[i])
                visited[i] = True
                self.dfs(cur_perm, visited, nums, all_perm)
                cur_perm.pop()
                visited[i] = False
        if is_end:
            all_perm.append(cur_perm.copy())

    # https://leetcode.com/problems/permutations/discuss/18296/Simple-Python-solution-(DFS).
    # # DFS
    # def permute(self, nums):
    #     res = []
    #     self.dfs(nums, [], res)
    #     return res
    #
    # def dfs(self, nums, path, res):
    #     if not nums:
    #         res.append(path)
    #         # return # backtracking
    #     for i in xrange(len(nums)):
    #         self.dfs(nums[:i] + nums[i + 1:], path + [nums[i]], res)


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.permute([1, 2, 3])
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        