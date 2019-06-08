// 43. Multiply Strings


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int> big_int(num1.length() + num2.length(), 0);
		for (int i = num1.length() - 1, k = big_int.size() - 1; i >= 0; --i, --k) {
			int n = num1[i] - '0';
			for (int j = num2.length() - 1, offset = 0; j >= 0; --j, ++offset) {
				int m = num2[j] - '0';
				big_int[k - offset] += n * m;
				big_int[k - offset - 1] += big_int[k - offset] / 10;
				big_int[k - offset] = big_int[k - offset] % 10;
			}
		}
		string result = "";
		int i = 0;
		while (i < big_int.size() && big_int[i] == 0)
			++i;
		if (i == big_int.size())
			return "0";
		for (int j = i; j < big_int.size(); ++j) {
			char n_ch = '0' + big_int[j];
			result += n_ch;
		}
		return result;
	}
}; 

//int main() {
//	Solution s = Solution();
//
//	string testcase1 = "123";
//	string testcase2 = "456";
//	
//	string ans = s.multiply(testcase1, testcase2);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}