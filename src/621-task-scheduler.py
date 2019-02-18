# 621. Task Scheduler

class Solution:
    def leastInterval(self, tasks: 'List[str]', n: 'int') -> 'int':
        ch2cnt = {}
        max_num = 1
        max_ch_cnt = 1
        for ch in tasks:
            if ch in ch2cnt:
                ch2cnt[ch] += 1
                if ch2cnt[ch] > max_num:
                    max_num = ch2cnt[ch]
                    max_ch_cnt = 1
                elif ch2cnt[ch] == max_num:
                    max_ch_cnt += 1
                else:
                    pass
            else:
                ch2cnt[ch] = 1
        ch2cnt = sorted(ch2cnt.items(), key=lambda x: x[1], reverse=True)
        empty_slots = (n - max_ch_cnt + 1) * (max_num - 1)
        avail_tasks = len(tasks) - max_num * max_ch_cnt
        idle = max(0, empty_slots - avail_tasks)
        return idle + len(tasks)


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()
    ans = s.leastInterval(['A','A','A','B','B','B','E','E','F','F','G','G'], 3)
    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))
        