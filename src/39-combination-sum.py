# 39. Combination Sum

class Solution:
    def combinationSum(self, candidates: 'List[int]', target: 'int') -> 'List[List[int]]':
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
            return
        for i in range(start, len(nums)):
            path.append(nums[i])
            self.backtrack(path, target - nums[i], nums, i, ans)
            path.pop()


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.combinationSum([2,3,5], 8)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        