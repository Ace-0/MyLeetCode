// 67. Add Binary


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string result = "";
		int i = a.length() - 1, j = b.length() - 1, sum = 0, carry = 0;
		while (i >= 0 || j >= 0) {
			int a_num = i >= 0 ? a[i] - '0' : 0;
			int b_num = j >= 0 ? b[j] - '0' : 0;
			int sum = a_num + b_num + carry;
			if (sum >= 2) {
				sum -= 2;
				carry = 1;
			}
			else {
				carry = 0;
			}
			result.push_back('0' + sum);
			--i;
			--j;
		}
		if (carry == 1)
			result.push_back('1');
		char temp = 0;
		int length = result.length();
		for (int k = 0; k < length / 2; ++k) {
			temp = result[k];
			result[k] = result[length - 1 - k];
			result[length - 1 - k] = temp;
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string a = "1010", b = "1011";
//	
//	string ans = s.addBinary(a, b);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}