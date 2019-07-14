// 264. Ugly Number II


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> ugly_nums;
		ugly_nums.push_back(1);
		int p_2 = 0, p_3 = 0, p_5 = 0;
		for (int i = 1; i < n; ++i) {
			int next = min(ugly_nums[p_2] * 2, min(ugly_nums[p_3] * 3, ugly_nums[p_5] * 5));
			ugly_nums.push_back(next);
			if (next == ugly_nums[p_2] * 2)
				++p_2;
			if (next == ugly_nums[p_3] * 3)
				++p_3;
			if (next == ugly_nums[p_5] * 5)
				++p_5;
		}
		return ugly_nums.back();
	}
};

//int main() {
//	Solution s = Solution();
//
//	int n = 10;
//	
//	int ans = s.nthUglyNumber(n);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}