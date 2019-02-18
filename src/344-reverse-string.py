# 344. Reverse String

class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        # return s[::-1]
        return "".join(reversed(s))
        

if __name__ == "__main__":
    import sys
    s = Solution()
    print(s.reverseString("hello"))
    print(s.reverseString("A man, a plan, a canal: Panama"))
        