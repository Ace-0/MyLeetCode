# 217. Contains Duplicate


class Solution:
    def containsDuplicate(self, nums: list) -> bool:
        hash_set = set()
        for n in nums:
            if n in hash_set:
                return True
            else:
                hash_set.add(n)
        return False


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = 0

    ans = s.function(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))