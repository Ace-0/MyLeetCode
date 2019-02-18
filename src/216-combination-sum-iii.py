# 216. Combination Sum III

class Solution:
    def combinationSum3(self, k: 'int', n: 'int') -> 'List[List[int]]':
        nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        ans = []
        path = []
        self.backtrack(path, n, k, nums, 0, ans)
        return ans

    def backtrack(self, path, target, limit, nums, start, ans):
        if target == limit == 0:
            ans.append(path.copy())
        if target > 0 and limit:
            for i in range(start, len(nums)):
                path.append(nums[i])
                self.backtrack(path, target - nums[i], limit - 1, nums, i + 1, ans)
                path.pop()

if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.combinationSum3(3, 9)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        