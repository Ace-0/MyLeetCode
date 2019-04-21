// 324. Wiggle Sort II


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> nums_sorted(nums);
		sort(nums_sorted.begin(), nums_sorted.end());
		int even_index, odd_index;
		if (nums.size() % 2 == 0) {
			odd_index = nums.size() - 1;
			even_index = odd_index - 1;
		}
		else {
			even_index = nums.size() - 1;
			odd_index = even_index - 1;
		}
		for (int i = 0; i < nums_sorted.size(); ++i) {
			if (even_index >= 0) {
				nums[even_index] = nums_sorted[i];
				even_index -= 2;
			}
			else {
				nums[odd_index] = nums_sorted[i];
				odd_index -= 2;
			}
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 1, 5, 1, 1, 6, 4 };
//	
//	s.wiggleSort(testcase);
//
//	for (int ans : testcase)
//		cout << ans << ' ';
//	cout << endl;
//
//	system("pause");
//	return 0;
//}