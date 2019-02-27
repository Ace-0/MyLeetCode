# 802. Find Eventual Safe States

from collections import deque, defaultdict


class Solution:
    def eventualSafeNodes(self, graph: list) -> list:
        queue = deque([])
        safe_states = []
        in_nodes = defaultdict(list)
        for i in range(len(graph)):
            if len(graph[i]) == 0:
                queue.append(i)
                safe_states.append(i)
            else:
                for j in graph[i]:
                    in_nodes[j].append(i)

        while len(queue):
            head = queue.popleft()
            for i in in_nodes[head]:
                graph[i].remove(head)
                if len(graph[i]) == 0:
                    queue.append(i)
                    safe_states.append(i)
        return sorted(safe_states)


if __name__ == "__main__":
    import time
    start = time.clock()

    s = Solution()

    test_case = [[1,2],[2,3],[5],[0],[5],[],[]]

    ans = s.eventualSafeNodes(test_case)

    print(ans)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))