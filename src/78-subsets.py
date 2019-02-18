# 78. Subsets

class Solution:
    # # 1. Recursive (Backtracking)
    # def subsets(self, nums: 'List[int]') -> 'List[List[int]]':
    #     total_set = []
    #     total_size = len(nums)
    #     for i, n in enumerate(nums):
    #         self.dfs([n], i, total_size, total_set, nums)
    #     total_set.append([])
    #     return total_set
    #
    # def dfs(self, cur_set, cur_idx, total_size, total_set, nums):
    #     total_set.append(cur_set.copy())
    #     for i in range(cur_idx + 1, total_size):
    #         cur_set.append(nums[i])
    #         self.dfs(cur_set, i, total_size, total_set, nums)
    #         cur_set.pop()

    # # 2. Iterative
    # def subsets(self, nums: 'List[int]') -> 'List[List[int]]':
    #     total_set = [[]]
    #     for n in nums:
    #         cur_size = len(total_set)
    #         for i in range(0, cur_size):
    #             new_subset = total_set[i].copy()
    #             new_subset.append(n)
    #             total_set.append(new_subset)
    #     return total_set

    # # 3. Bit Manipulation

if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.subsets([1,2,3,4])
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        