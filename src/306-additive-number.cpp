// 306. Additive Number


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isAdditiveNumber(string num) {
		int num_len = num.length();
		for (int len_a = 1; len_a <= num_len / 2; ++len_a) {
			for (int len_b = 1; len_b <= num_len / 2; ++len_b) {
				if (is_valid(0, len_a, len_b, num, num_len))
					return true;
			}
		}
		return false;
	}
private:
	bool is_valid(int start, int len_a, int len_b, const string& num, const int num_len) {
		int start_a = start, start_b = start + len_a, start_c = start + len_a + len_b;
		if (start_c == num_len) return start != 0;
		int min_len_c = min(len_a, len_b);
		if ((num[start_a] == '0' && len_a > 1) || (num[start_b] == '0' && len_b > 1))
			return false;
		long num_a = stol(num.substr(start_a, len_a)), num_b = stol(num.substr(start_b, len_b));
		for (int len_c = min_len_c; start_c + len_c <= num_len; ++len_c) {
			if (len_c > 1 && num[start_c] == '0')
				return false;
			long num_c = stol(num.substr(start_c, len_c));
			if (num_c > num_a + num_b)
				return false;
			else if (num_c == num_a + num_b)
				return is_valid(start_b, len_b, len_c, num, num_len);
		}
		return false;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "123581321";
//	
//	bool ans = s.isAdditiveNumber(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}