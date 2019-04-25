// 166. Fraction to Recurring Decimal


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0)
			return "0";
		string result = "";
		if (numerator < 0 ^ denominator < 0)
			result += "-";
		long n = labs(numerator);
		long d = labs(denominator);
		result += to_string(n / d);
		long r = n % d;
		if (r == 0)
			return result;
		result += ".";
		unordered_map<int, int> last_position;
		while (r != 0) {
			if (r != 0 && last_position.find(r) != last_position.end()) {
				result.insert(last_position[r], "(");
				result += ")";
				return result;
			}
			else {
				last_position[r] = result.size();
			}
			r *= 10;
			result += to_string(r / d);
			r = r % d;
		}
		return result;
	}
};
//
//int main() {
//	Solution s = Solution();
//
//	string ans = s.fractionToDecimal(1, 6);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}