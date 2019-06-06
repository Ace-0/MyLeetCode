// 532. K-diff Pairs in an Array


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (nums.size() < 2 || k < 0)
			return 0;
		unordered_map<int, int> hashmap;
		int count = 0;
		for (int n : nums) {
			if (hashmap.find(n) == hashmap.end()) {
				if (hashmap.find(n - k) != hashmap.end())
					++count;
				if (hashmap.find(n + k) != hashmap.end())
					++count;
				hashmap[n] = 1;
			}
			else {
				if (k == 0 && hashmap[n] == 1)
					++count;
				hashmap[n] = 2;
			}
		}
		return count;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 3, 1, 4, 1, 5 };
//	int k = 0;
//	
//	int ans = s.findPairs(testcase, k);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}