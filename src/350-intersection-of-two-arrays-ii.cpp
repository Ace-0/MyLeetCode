// 350. Intersection of Two Arrays II

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_map<int, int> hash_map;
		for (int n : nums1) {
			hash_map[n] += 1;
		}
		for (int n : nums2) {
			if (hash_map.find(n) != hash_map.end() && hash_map[n] > 0) {
				result.push_back(n);
				hash_map[n] -= 1;
			}
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase1 = { 4, 9, 5 };
//	vector<int> testcase2 = { 9, 4, 9, 8, 4 };
//
//	vector<int> ans = s.intersect(testcase1, testcase2);
//
//	for (int n : ans)
//		cout << n << ' ';
//	cout << endl;
//
//	system("pause");
//	return 0;
//}