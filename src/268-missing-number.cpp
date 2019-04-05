// 268. Missing Number

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum_of_nums = 0;
		for (int n : nums)
			sum_of_nums += n;
		return (1 + nums.size()) * nums.size() / 2 - sum_of_nums;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 9,6,4,2,3,5,7,0,1 };
//	
//	int ans = s.missingNumber(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}