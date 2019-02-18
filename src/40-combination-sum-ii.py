# 40. Combination Sum II

class Solution:
    def combinationSum2(self, candidates: 'List[int]', target: 'int') -> 'List[List[int]]':
        ans = []
        path = []
        candidates.sort()
        self.backtrack(path, target, candidates, 0, ans)
        return ans

    def backtrack(self, path, target, nums, start, ans):
        if target < 0:
            return
        if target == 0:
            ans.append(path.copy())
        for i in range(start, len(nums)):
            if i > start and nums[i] == nums[i - 1]:
                continue
            path.append(nums[i])
            self.backtrack(path, target - nums[i], nums, i + 1, ans)
            path.pop()

    # def backtrack(self, path, target, nums, start, ans):
    #     if target < 0:
    #         return
    #     if target == 0:
    #         ans.append(path.copy())
    #         return
    #     i = start
    #     while i < len(nums):
    #         diff_idx = i + 1
    #         while diff_idx < len(nums) and nums[diff_idx] == nums[i]:
    #             diff_idx += 1
    #         val = nums[i]
    #         for add_num in range(1, diff_idx - i + 1):
    #             path += [val] * add_num
    #             self.backtrack(path, target - val * add_num, nums, diff_idx, ans)
    #             for t in range(0, add_num):
    #                 path.pop()
    #         i = diff_idx


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.combinationSum2([10,1,2,7,6,1,5], 8)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        