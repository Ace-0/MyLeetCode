// 66. Plus One


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int i = digits.size() - 1;
		++digits[i];
		while (digits[i] == 10) {
			if (i - 1 >= 0) {
				digits[i] = 0;
				++digits[i - 1];
				--i;
			}
			else {
				digits[i] = 0;
				digits.insert(digits.begin(), 1);
				break;
			}
		}
		return digits;
	}
};
