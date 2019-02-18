# 412. Fizz Buzz

class Solution:
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        li = []
        for i in range(1, n + 1):
            if i % 3 == 0 and i % 5 == 0:
                li.append("FizzBuzz")
            elif i % 3 == 0:
                li.append("Fizz")
            elif i % 5 == 0:
                li.append("Buzz")
            else:
                li.append(str(i))
        return li
        # return ['Fizz' * (not i % 3) + 'Buzz' * (not i % 5) or str(i) for i in range(1, n+1)]
        

if __name__ == "__main__":
    import sys
    s = Solution()
    print(s.fizzBuzz(15))
        