// 5273. Search Suggestions System


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
    int numWays(int steps, int arrLen) {
		int mod = 1000000000 + 7;
        vector<int> pre(arrLen, 0);
		vector<int> cur(arrLen, 0);
		pre[0] = 1;
		for (int s = 1; s <= steps; ++s) {
			for (int i = 0; i < min(s + 1, arrLen); ++i) {
				cur[i] = 0;
				if (i - 1 >= 0)
					cur[i] = (cur[i] + pre[i - 1]) % mod;
				cur[i] = (cur[i] + pre[i]) % mod;
				if (i + 1 < arrLen)
					cur[i] = (cur[i] + pre[i + 1]) % mod;
				cur[i] %= mod;
			}
			pre = cur;
		}
		return cur[0];
    }
};

// int main() {
// 	Solution s = Solution();

// 	int ans1 = s.numWays(3, 2);
// 	int ans2 = s.numWays(2, 4);
// 	int ans3 = s.numWays(4, 2);
// 	int ans4 = s.numWays(27, 7);
// 	int ans5 = s.numWays(438, 315977);

// 	return 0;
// }