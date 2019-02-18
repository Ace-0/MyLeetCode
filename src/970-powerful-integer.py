# 970. Powerful Integer

class Solution:
    def powerfulIntegers(self, x, y, bound):
        """
        :type x: int
        :type y: int
        :type bound: int
        :rtype: List[int]
        """
        ########################################################
        # # Brutal Solution: TLE
        # x_list = []
        # if x == 1:
        #     x_list.append(1)
        # else:
        #     xi = 0
        #     x_pro = 1
        #     while x_pro <= bound:
        #         x_list.append(x_pro)
        #         xi += 1
        #         x_pro = x**xi

        # y_list = []
        # if y == 1:
        #     y_list.append(1)
        # else:
        #     yi = 0
        #     y_pro = 1
        #     while y_pro <= bound:
        #         y_list.append(y_pro)
        #         yi += 1
        #         y_pro = y**yi

        # ans = []
        # for i in range(2, bound + 1):
        #     found = 0
        #     for x_ele in x_list:
        #         if found:
        #             break
        #         if y_list.count(i - x_ele):
        #             found = 1
        #             ans.append(i)
        #             break
        # return ans
        
        ########################################################
        # # Brutal Solution: Accepted 60ms
        # import math

        # if bound == 0:
        # 	return []
        # if x == 1:
        # 	sum1 = [1]
        # else:
        # 	sum1 = [x ** i for i in range(int(math.log(bound, x)) + 1)]
        # if y == 1:
        # 	sum2 = [1]
        # else:
        # 	sum2 = [y ** i for i in range(int(math.log(bound, y)) + 1)]

        # ans = set()
        # for i in sum1:
        # 	for j in sum2:
        # 		if i+j <= bound:
        # 			ans.add(i+j)

        # return list(ans)

        ########################################################
        # # Brutal Solution: Accepted 32ms
        from math import log

        if bound == 0: return []
        result = set()
        boundi, boundj = int(log(bound, max(x, 2))) + 1, int(log(bound, max(y, 2))) + 1
        for i in range(boundi):
            for j in range(boundj):
                item = x**i + y**j
                if item > bound:
                    break
                result.add(item)
        return list(result)

        ########################################################
        # # Brutal BFS: TLE 32ms
        # res = set()
        
        # def helper(last_num, left, right):
        #     value = left + right
        #     # print(left, right)
        #     if value <= bound:
        #         res.add(value)
        #         if x != 1:
        #             helper(value, left*x, right)
        #         if y != 1:
        #             helper(value, left, right*y)
            
        # helper(0, 1, 1)
        # return list(res)

if __name__ == "__main__":
    import time
    start = time.clock()
    
    s = Solution()
    
    ans = s.powerfulIntegers(90, 100, 1000000)

    end = time.clock()
    print('Running time: %s Seconds'%(end-start))
    
    print(ans)
        