// 220. Contains Duplicate III


#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<int> exist;
		for (int i = 0; i < nums.size(); ++i) {
			if (i - k - 1 >= 0)
				exist.erase(nums[i - k - 1]);
			set<int>::iterator lower_bound = exist.lower_bound((long)(nums[i] - t));
			if (lower_bound != exist.end() && abs(*lower_bound - nums[i]) <= t)
				return true;
			exist.insert(nums[i]);
		}
		return false;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 10, 26, 1, 5, 9, 1, 5, 9 };
//	int k = 2;
//	int t = 3;
//	
//	bool ans = s.containsNearbyAlmostDuplicate(testcase, k, t);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}