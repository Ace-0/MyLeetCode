// 163. Missing Ranges


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> results;
		long lower_l = lower;
		for (int n : nums) {
			long diff = n - lower_l;
			if (diff > 1)
				results.push_back(to_string(lower_l) + "->" + to_string(n - 1));
			else if (diff == 1)
				results.push_back(to_string(lower_l));
			lower_l = (long)n + 1;
		}
		long diff = upper - lower_l;
		if (diff > 0)
			results.push_back(to_string(lower_l) + "->" + to_string(upper));
		else if (diff == 0)
			results.push_back(to_string(lower_l));
		return results;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> nums = { 0, 1, 3, 50, 75 };
//	int lower = 0;
//	int upper = 99;
//	
//	vector<string> ans = s.findMissingRanges(nums, lower, upper);
//
//	cout << "[";
//	for (string a : ans)
//		cout << a << ",";
//	cout << "]" << endl;
//
//	system("pause");
//	return 0;
//}