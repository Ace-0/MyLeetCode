# 84. Largest Rectangle in Histogram

class Solution:
    def largestRectangleArea(self, heights: 'List[int]') -> 'int':
        if len(heights) == 0:
            return 0
        first_lower_left = [0] * len(heights)  # index of the first bar that is lower than heights[i] on its left
        first_lower_right = [0] * len(heights) # index of the first bar that is lower than heights[i] on its right
        first_lower_left[0] = -1
        first_lower_right[len(heights) - 1] = len(heights)

        for i in range(1, len(heights)):
            idx = i - 1
            while idx >= 0 and heights[idx] >= heights[i]:
                idx = first_lower_left[idx]
            first_lower_left[i] = idx

        for i in range(len(heights) - 2, -1, -1):
            idx = i + 1
            while idx < len(heights) and heights[idx] >= heights[i]:
                idx = first_lower_right[idx]
            first_lower_right[i] = idx

        max_area = 0
        for i in range(0, len(heights)):
            max_area = max(max_area, (first_lower_right[i] - first_lower_left[i] - 1) * heights[i])
        return max_area

        ## TLE
        # for i in range(0, len(heights)):
        #     li = i - 1
        #     while li >= 0 and heights[li] >= heights[i]:
        #         li -= 1
        #     edge_from_left = li
        #     ri = i + 1
        #     while ri < len(heights) and heights[ri] >= heights[i]:
        #         ri += 1
        #     edge_from_right = ri
        #     max_area = max(max_area, (edge_from_right - edge_from_left - 1) * heights[i])
        # return max_area


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.largestRectangleArea([2,1,5,6,2,3])
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        