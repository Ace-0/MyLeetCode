# 42. Trapping Rain Water

class Solution:
    def trap(self, height: 'List[int]') -> 'int':
        start_idx = 0
        end_idx = 0
        start_h = 0
        last_h = 0
        rain = 0
        idx = 0
        while idx < len(height):
            if idx
            while height[i] < start_h:


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.trap([0,1,0,2,1,0,1,3,2,1,2,1])
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        