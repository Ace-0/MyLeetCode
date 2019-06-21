// 60. Permutation Sequence


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> nums, factorial;
		factorial.push_back(1);
		for (int i = 1; i <= n; ++i) {
			nums.push_back(i);
			factorial.push_back(factorial[i - 1] * i);
		}
		string result = "";
		k = k - 1;
		for (int i = 1; i <= n; ++i) {
			int cur_index = k / factorial[n - i];
			int cur_num = nums[cur_index];
			nums.erase(nums.begin() + cur_index);
			char cur_ch = '0' + cur_num;
			result += cur_ch;
			k = k % factorial[n - i];
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int n = 3;
//	int k = 3;
//	
//	string ans = s.getPermutation(n, k);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}