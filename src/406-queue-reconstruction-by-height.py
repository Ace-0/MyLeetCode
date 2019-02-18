# 406. Queue Reconstruction by Height

from functools import cmp_to_key

class Solution:
    def reconstructQueue(self, people):
        """
        :type args:
        :rtype:
        """
        def compare(x, y):
            if x[0] < y[0]:
                return 1
            elif x[0] > y[0]:
                return -1
            else:
                if x[1] > y[1]:
                    return 1
                else:
                    return -1

        number = len(people)
        ans = [[-1, -1] for n in range(0, number)]
        sort_by_height = sorted(people, key=cmp_to_key(compare))
        num_left  = number
        while num_left:
            k = sort_by_height[num_left - 1][1]
            cnt = 0
            index = 0
            while cnt < k:
                if ans[index][0] == -1:
                    cnt += 1
                index += 1
            while ans[index][0] != -1:
                index += 1
            ans[index] = sort_by_height[num_left - 1]
            num_left -= 1
            # print(ans)
        return ans


if __name__ == "__main__":
    import time
    start = time.clock()

    input = [[8,2],[4,2],[4,5],[2,0],[7,2],[1,4],[9,1],[3,1],[9,0],[1,0]]
    s = Solution()
    ans = s.reconstructQueue(input)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        