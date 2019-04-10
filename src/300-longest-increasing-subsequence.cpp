// 300. Longest Increasing Subsequence


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> tail_vec;
		if (nums.empty())
			return 0;
		tail_vec.push_back(nums[0]);

		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] <= tail_vec[0]) {
				tail_vec[0] = nums[i];
			}
			else if (nums[i] > tail_vec[tail_vec.size() - 1]) {
				tail_vec.push_back(nums[i]);
			}
			else {
				int to_replace = getListIndexBinarySearch(nums[i], tail_vec) + 1;
				tail_vec[to_replace] = nums[i];
			}
		}
		return tail_vec.size();
	}

	int getListIndexBinarySearch(int target, const vector<int>& tail_vec) {
		// find the largest tail element that is smaller than target
		int left = 0, right = tail_vec.size() - 1;
		while (left < right) {
			int mid = left + (right - left + 1) / 2;  // +1 to make mid tend to right
			if (tail_vec[mid] < target)
				left = mid;
			else
				right = mid - 1;
		}
		return left;
	}
};

//class Solution {
//public:
//	int lengthOfLIS(vector<int>& nums) {
//		vector<vector<int>> lists;
//		if (nums.empty())
//			return 0;
//		lists.emplace_back(1, nums[0]);
//
//		for (int i = 1; i < nums.size(); ++i) {
//			vector<int> longest_list = lists[lists.size() - 1];
//			if (nums[i] <= lists[0][lists[0].size() - 1]) {
//				lists[0][0] = nums[i];
//			}
//			else if (nums[i] > longest_list[longest_list.size() - 1]) {
//				vector<int> ext_vec = longest_list;
//				ext_vec.push_back(nums[i]);
//				lists.push_back(ext_vec);
//			}
//			else {
//				int to_replace = getListIndexBinarySearch(nums[i], lists) + 1;
//				lists[to_replace][lists[to_replace].size() - 1] = nums[i];
//			}
//		}
//		return lists[lists.size() - 1].size();
//	}
//
//	int getListIndexBinarySearch(int target, const vector<vector<int>>& lists) {
//		// find the largest tail element that is smaller than target
//		int left = 0, right = lists.size() - 1;
//		while (left < right) {
//			int mid = left + (right - left + 1) / 2;  // +1 to make mid tend to right
//			if (lists[mid][lists[mid].size() - 1] < target)
//				left = mid;
//			else
//				right = mid - 1;
//		}
//		return left;
//	}
//};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 4,10,4,3,8,9 };
//	
//	int ans = s.lengthOfLIS(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}