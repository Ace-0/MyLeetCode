// 12. Integer to Roman


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		vector<char> ones = { 'I', 'X', 'C', 'M' };
		vector<char> fives = { 'V', 'L', 'D' };
		int base = 0;
		string result = "";
		while (num > 0) {
			int bit = num % 10;
			if (bit == 9) {
				result.insert(0, 1, ones[base + 1]);
				result.insert(0, 1, ones[base]);
			}
			else if (bit >= 5) {
				for (int i = 0; i < bit - 5; ++i)
					result.insert(0, 1, ones[base]);
				result.insert(0, 1, fives[base]);
			}
			else if (bit == 4) {
				result.insert(0, 1, fives[base]);
				result.insert(0, 1, ones[base]);
			}
			else {
				for (int i = 0; i < bit; ++i)
					result.insert(0, 1, ones[base]);
			}
			num /= 10;
			++base;
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int testcase = 49;
//	
//	string ans = s.intToRoman(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}