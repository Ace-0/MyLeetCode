# 394. Decode String

class Solution:
    def decodeString(self, s: 'str') -> 'str':
        ans, end = self.helper(s, 0)
        return ans

    def helper(self, s, start):
        cur_str = ''
        i = start
        while i < len(s):
            if ord('0') <= ord(s[i]) <= ord('9'):
                num_str = ''
                while ord('0') <= ord(s[i]) <= ord('9'):
                    num_str += s[i]
                    i += 1
                number = int(num_str)
                sub_str, sub_end = self.helper(s, i + 1)
                cur_str += number * sub_str
                i = sub_end + 1
            elif s[i] == ']':
                return cur_str, i
            else:
                cur_str += s[i]
                i += 1
        return cur_str, 0


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.decodeString('10[a2[c]]')
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        