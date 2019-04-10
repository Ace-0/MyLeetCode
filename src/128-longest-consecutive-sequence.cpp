// 128. Longest Consecutive Sequence

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// hash set, find the start of the sequence
// 12ms, 10MB
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> set;
		for (int n : nums)
			set.insert(n);
		int max_streak = 0;
		for (int n : set) {
			if (set.find(n - 1) == set.end()) {
				int cur_streak = 1;
				int cur_num = n + 1;
				while (set.find(cur_num) != set.end()) {
					cur_streak += 1;
					cur_num += 1;
				}
				max_streak = cur_streak > max_streak ? cur_streak : max_streak;
			}
		}
		return max_streak;
	}
};

//// hash map, record the length of boundries
//// 12ms 10MB
//class Solution {
//public:
//	int longestConsecutive(vector<int>& nums) {
//		// map[a] = n means the length of the sequence is n
//		// when a is one of the boundries of the sequence
//		unordered_map<int, int> map;
//		int max_length = 0;
//		for (int n : nums) {
//			if (map.find(n) == map.end()) {
//				int left_length = map.find(n - 1) == map.end() ? 0 : map[n - 1];
//				int right_length = map.find(n + 1) == map.end() ? 0 : map[n + 1];
//				int total_length = left_length + right_length + 1;
//				max_length = total_length > max_length ? total_length : max_length;
//				// we must put n in map even though it is not a boundary
//				// actually, map[n] = any number is ok
//				map[n] = total_length;
//
//				map[n - left_length] = total_length;
//				map[n + right_length] = total_length;
//			}
//		}
//		return max_length;
//	}
//};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3 };
//	
//	int ans = s.longestConsecutive(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}