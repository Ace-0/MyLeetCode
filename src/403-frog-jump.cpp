// 403. Frog Jump


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool canCross(vector<int>& stones) {
		unordered_map<int, unordered_set<int>> reach_with_steps;
		reach_with_steps[0] = { 0 };
		for (int& cur_pos : stones) {
			for (int step : reach_with_steps[cur_pos]) {
				if (step > 1)
					reach_with_steps[cur_pos + step - 1].insert(step - 1);
				reach_with_steps[cur_pos + step].insert(step);
				reach_with_steps[cur_pos + step + 1].insert(step + 1);
			}
		}
		return !reach_with_steps[stones.back()].empty();
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 0,1,3,5,6,8,12,17 };
//	
//	bool ans = s.canCross(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}