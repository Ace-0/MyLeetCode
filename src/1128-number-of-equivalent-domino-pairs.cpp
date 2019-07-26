// 1128. Number of Equivalent Domino Pairs


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		unordered_map<int, int> domino_cnt;
		int equal_cnt = 0;
		for (vector<int>& domino : dominoes) {
			int val = domino[0] * 10 + domino[1];
			if (domino_cnt.find(val) != domino_cnt.end()) {
				equal_cnt += domino_cnt[val];
			}
			++domino_cnt[val];
			if (domino[0] != domino[1]) {
				int rev_val = domino[1] * 10 + domino[0];
				++domino_cnt[rev_val];
			}
		}
		return equal_cnt;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> testcase = { {1,1}, {2,2}, {1,1}, {1,2}, {1,2}, {1,1} };
//
//	int ans = s.numEquivDominoPairs(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
