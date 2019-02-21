# 42. Trapping Rain Water

class Solution:
    def trap(self, height: 'List[int]') -> 'int':
        if len(height) == 0:
            return 0
        total_water = 0
        i = 0
        stack = []
        while i < len(height):
            if len(stack) == 0 or height[i] <= height[stack[-1]]:
                stack.append(i)
            else:
                while len(stack) and height[stack[-1]] < height[i]:
                    lowest = stack.pop()
                    if len(stack):
                        left = stack.pop()
                        stack.append(left)
                        right = i
                        w = right - left - 1
                        h = min(height[left], height[right]) - height[lowest]
                        total_water += w * h
                stack.append(i)
            i += 1
        return total_water


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.trap([2,1,0,2])
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        