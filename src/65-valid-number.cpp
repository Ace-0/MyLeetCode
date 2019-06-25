// 65. Valid Number


#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		return regex_match(s, regex("^\\s*(\\+|-)?(\\d+(\\.\\d*)?|\\.\\d+)(e(\\+|-)?\\d+)?\\s*$"));
	}
};

//int main() {
//	Solution s = Solution();
//
//	cout << "\t" << "RESULT" << "\t" << "EXPECTED" << endl;
//	cout << "\t" << s.isNumber("0") << "\t" << true << endl;
//	cout << "\t" << s.isNumber("0.1") << "\t" << true << endl;
//	cout << "\t" << s.isNumber(" 0.1 ") << "\t" << true << endl;
//	cout << "\t" << s.isNumber("abc") << "\t" << false << endl;
//	cout << "\t" << s.isNumber("1 a") << "\t" << false << endl;
//	cout << "\t" << s.isNumber("2e10") << "\t" << true << endl;
//	cout << "\t" << s.isNumber(" -90e3   ") << "\t" << true << endl;
//	cout << "\t" << s.isNumber(" 1e") << "\t" << false << endl;
//	cout << "\t" << s.isNumber("e3") << "\t" << false << endl;
//	cout << "\t" << s.isNumber(" 6e-1") << "\t" << true << endl;
//	cout << "\t" << s.isNumber(" 99e2.5 ") << "\t" << false << endl;
//	cout << "\t" << s.isNumber("53.5e93") << "\t" << true << endl;
//	cout << "\t" << s.isNumber(" --6 ") << "\t" << false << endl;
//	cout << "\t" << s.isNumber("-+3") << "\t" << false << endl;
//	cout << "\t" << s.isNumber("95e54e53") << "\t" << false << endl;
//
//	system("pause");
//	return 0;
//}