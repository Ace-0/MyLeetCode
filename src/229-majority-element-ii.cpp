// 229. Majority Element II


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int x = 0, y = 1, x_cnt = 0, y_cnt = 0;
		for (int n : nums) {
			if (n == x) {
				++x_cnt;
			}
			else if (n == y) {
				++y_cnt;
			}
			else if (x_cnt == 0) {
				x = n;
				x_cnt = 1;
			}
			else if (y_cnt == 0) {
				y = n;
				y_cnt = 1;
			}
			else {
				--x_cnt;
				--y_cnt;
			}
		}
		x_cnt = 0;
		y_cnt = 0;
		for (int n : nums) {
			if (n == x)
				++x_cnt;
			if (n == y)
				++y_cnt;
		}
		vector<int> result;
		if (x_cnt > nums.size() / 3)
			result.push_back(x);
		if (y_cnt > nums.size() / 3)
			result.push_back(y);
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 2, 2, 2 };
//	
//	vector<int> ans = s.majorityElement(testcase);
//
//	for (int n : ans)
//		cout << n << " ";
//	cout << endl;
//
//	system("pause");
//	return 0;
//}