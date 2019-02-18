# 215. Kth Largest Element in an Array

class Solution:
    def findKthLargest(self, nums: 'List[int]', k: 'int') -> 'int':
        low = 0
        high = len(nums) - 1
        k = len(nums) - k
        while low < high:
            pivot = self.partition(nums, low, high)
            if pivot > k:
                high = pivot - 1
            elif pivot < k:
                low = pivot + 1
            else:
                return nums[pivot]
        return nums[k]

    def partition(self, nums, low, high):
        i = low + 1
        j = high
        p = nums[low]
        while True:
            while nums[i] < p and i < high:
                i += 1
            while p < nums[j] and j > low:
                j -= 1
            if i >= j:
                break
            self.swap(nums, i, j)
            print(nums)
        self.swap(nums, low, j)
        print(nums)
        return j

    def swap(self, nums, i, j):
        tmp = nums[i]
        nums[i] = nums[j]
        nums[j] = tmp


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.findKthLargest([3,2,3,1,2,4,5,5,6], 4)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        