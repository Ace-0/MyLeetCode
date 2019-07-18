// 354. Russian Doll Envelopes


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b) {
			if (a[0] == b[0])
				return a[1] > b[1];
			else
				return a[0] < b[0];
		});
		vector<int> dp;
		for (vector<int> env : envelopes) {
			vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), env[1]);
			if (it == dp.end())
				dp.push_back(env[1]);
			else
				*it = env[1];
		}
		return dp.size();
	}
};

//int main() {
//	Solution s = Solution();
//
//	//vector<vector<int>> testcase = { {5,4},{6,4},{6,7},{2,3} };
//	vector<vector<int>> testcase = { {1,1},{1,1},{1,1},{1,1} };
//
//	int ans = s.maxEnvelopes(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}